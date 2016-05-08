#include "dbl_link.h"
#include "dbl_link.cpp"

#ifndef LARGE_INT
#define LARGE_INT

template <class type>
class LargeInt {

    private:
        DoublyLinkedList large_int;
        friend ostream &operator<<(ostream &, const int &);
        friend istream &operator>>(istream &, const int &);
    public:
        LargeInt();
        LargeInt& operator+(const LargeInt&);
        LargeInt& operator-(const LargeInt&);
        LargeInt& operator*(const LargeInt&);
        LargeInt& operator/(const LargeInt&);
        LargeInt& operator%(const LargeInt&);
        bool operator==(const LargeInt&);
        bool operator<(const LargeInt&);
        bool operator>(const LargeInt&);
        bool operator<=(const LargeInt&);
        bool operator>=(const LargeInt&);
};
