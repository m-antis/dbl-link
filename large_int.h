

#ifndef LARGE_INT
#define LARGE_INT

#include "dbl_link.cpp"

class LargeInt {
    friend ostream& operator<<(ostream &, LargeInt);
    friend istream& operator>>(istream &, LargeInt &);

    static const int POSITIVE=1;
    static const int NEGATIVE=0;

    private:
        DoublyLinkedList<int> large_int;
        int sign;

        bool isDigit(char);
        LargeInt add(LargeInt &);
        LargeInt subtract(LargeInt &);
        LargeInt multiply(LargeInt &);
        LargeInt divide(LargeInt &, bool mod=false);

        void removeLeadingZeros();
    public:
        LargeInt();

        LargeInt operator+(LargeInt&);
        LargeInt operator-(LargeInt&);
        LargeInt operator*(LargeInt&);
        LargeInt operator/(LargeInt&);
        LargeInt operator%(LargeInt&);
        bool operator==(LargeInt&);
        bool operator<(LargeInt&);
        bool operator>(LargeInt&);
        bool operator<=(LargeInt&);
        bool operator>=(LargeInt&);
};

#endif