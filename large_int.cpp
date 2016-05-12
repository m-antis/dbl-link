#include <limits>
#include "large_int.h"


ostream& operator<<(ostream &out, LargeInt li) {
    int i;

    if (li.sign == LargeInt::NEGATIVE)
        out<<'-';

    li.large_int.moveFirst();
    while(!li.large_int.EOF()){
        li.large_int.iterData(i);
        out<<i;
        li.large_int.moveNext();
    }
    return out<<endl;
}

istream& operator>>(istream &in, LargeInt &li){
    li.large_int.destroyList();
    char c;
    int i;
    bool lZero = true;

    c = (char)in.peek();

    //remove preceding whitespace
    while (c == ' '){
        in>>c;
    }

    //sets sign of int
    if (c == '-'){
        li.sign = LargeInt::NEGATIVE;
        in>>c;
    }

    while(!in.eof() && (char)in.peek() != '\n'){
        in>>c;

        if (li.isDigit(c)){
            i = c - '0';
            //dont allow leading zeros
            if(!(lZero and i == 0)) {
                li.large_int.append(i);
                lZero = false;
            }
        }
        else{
            //Once it finds a non digit, run through the rest of the characters.
            in.clear();
            while (in.peek() != '\n') { in>>c; }
        }
    }
    in.clear();
    in.ignore(numeric_limits<streamsize>::max(),'\n');
    return in;
}

bool LargeInt::isDigit(char c){
    return c-'0'<10 && c-'0'>-1;
}

LargeInt LargeInt::add(LargeInt &li) {
    LargeInt tempLi;
    //if one largeInt is negative...subtract instead
    if (!(sign * li.sign)){

        int sign1, sign2;
        sign1 = sign;
        sign2 = li.sign;
        sign = li.sign = POSITIVE;


        if(!sign1 && !sign2){
            tempLi = add(li);
            tempLi.sign = NEGATIVE;
        }else if (*this>li){
            tempLi = subtract(li);
            tempLi.sign = sign1;
        }else{
            tempLi = li.subtract(*this);
            tempLi.sign = sign2;
        }

        sign = sign1;
        li.sign = sign2;
        return tempLi;
    }

    int v1, v2, carry;
    int mLength;


    carry = 0;
    mLength = large_int.getLength() > li.large_int.getLength() ? large_int.getLength() : li.large_int.getLength();

    large_int.moveLast();
    li.large_int.moveLast();
    for (int i = 0; i < mLength; ++i) {


        v1 = v2 = 0;
        large_int.iterData(v1);
        li.large_int.iterData(v2);

        tempLi.large_int.prepend(((v1+v2+carry)%10));
        carry = (v1+v2+carry)/10;

        large_int.movePrev();
        li.large_int.movePrev();
    }
    if (carry != 0){
        tempLi.large_int.prepend(carry);
    }
    return tempLi;
}

LargeInt LargeInt::subtract(LargeInt &li) {
    LargeInt tempLi;

    int sign1, sign2;
    sign1 = sign;
    sign2 = li.sign;
    sign = li.sign = POSITIVE;

    if (sign1 != sign2){
        tempLi = add(li);
        tempLi.sign = sign1;
        return tempLi;
    }

    if (li>*this){
        tempLi = li.subtract(*this);
        tempLi.sign = !sign1;
        return tempLi;
    }

    if (!sign1 && !sign2){
        tempLi = subtract(li);
        tempLi.sign = NEGATIVE;
        return tempLi;
    }

    sign = sign1;
    li.sign = sign2;

    int v1, v2, sub;
    int mLength;


    sub = 0;
    mLength = large_int.getLength() > li.large_int.getLength() ? large_int.getLength() : li.large_int.getLength();

    large_int.moveLast();
    li.large_int.moveLast();
    for (int i = 0; i < mLength; ++i) {
        v1 = v2 = 0;
        large_int.iterData(v1);
        li.large_int.iterData(v2);

        v1 -= sub;

        if (v1 < v2){
            v1 += 10;
            sub=1;
        }else{
            sub=0;
        }

        tempLi.large_int.prepend(v1-v2);

        large_int.movePrev();
        li.large_int.movePrev();
    }
    tempLi.removeLeadingZeros();
    return tempLi;
}

void LargeInt::removeLeadingZeros() {
    int i = 0;

    while (large_int.getLength()>1 && i == 0) {
        large_int.moveFirst();
        large_int.iterData(i);
        if (i == 0)
            large_int.destroyFirstNode();
    }
}

LargeInt LargeInt::operator+(LargeInt &li) {
    return add(li);
}

LargeInt LargeInt::operator-(LargeInt &li) {
    return subtract(li);
}

bool LargeInt::operator==(LargeInt &li) {
    if ((large_int.getLength() != li.large_int.getLength()) || (sign != li.sign))
        return false;

    int v1, v2;
    v1=v2=0;

    large_int.moveFirst();
    li.large_int.moveFirst();
    while (!large_int.EOF()){
        large_int.iterData(v1);
        li.large_int.iterData(v2);
        if (v1 != v2)
            return false;
        large_int.moveNext();
        li.large_int.moveNext();
    }
    return true;
}

bool LargeInt::operator<(LargeInt &li) {
    //if they have different signs
    if(sign != li.sign){
        //if this.sign is negative, its smaller
        return sign == 0;
    }

    //if they have different lengths (we know they have the same sign)
    if (large_int.getLength() > li.large_int.getLength())
        return sign == 0; //if both are negative, then  its smaller;

    int v1, v2;
    v1=v2=0;

    large_int.moveFirst();
    li.large_int.moveFirst();

    while(!large_int.EOF() && v1 == v2){
        large_int.iterData(v1);
        li.large_int.iterData(v2);
        large_int.moveNext();
        li.large_int.moveNext();
    }

    //if they are both positive v1<v2, else v2<v1
    return sign ? v1<v2 : v2<v1;
}

bool LargeInt::operator>(LargeInt &li) {

    if(sign != li.sign){
        return sign == 1;
    }

    if (large_int.getLength() != li.large_int.getLength())
        return large_int.getLength()>li.large_int.getLength();

    int v1, v2;
    v1=v2=0;

    large_int.moveFirst();
    li.large_int.moveFirst();

    while(!large_int.EOF() && v1 == v2){
        large_int.iterData(v1);
        li.large_int.iterData(v2);
        large_int.moveNext();
        li.large_int.moveNext();
    }

    return sign ? v1>v2 : v2>v1;

}

bool LargeInt::operator<=(LargeInt &li) {
    return *this==li || *this<li;
}
bool LargeInt::operator>=(LargeInt &li) {
    return *this==li || *this>li;
}

LargeInt::LargeInt() {
    sign = POSITIVE;
}


