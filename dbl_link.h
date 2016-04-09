  /* * * * * * * * * * * * * * * * * *
* File:          dbl_link.h
* Authors:       Michael Antis, Arthur Bonini
* Description:   ~ Header file for CSC 330 Project 3, Doubly Linked List
*                ~ This file contains the defined types for Doubly Linked List
*
*
*/

#include <iostream>
#ifndef DBL_LINK
#define DBL_LINK


template <class type>
struct Node {
    type datum;
    Node<type> *prev;
    Node<type> *next;
};


template <class type>
class DoublyLinkedList {
    private:
        friend ostream &operator<<(ostream &, const Node<type> &);
        friend istream &operator>>(istream &, Node<type> &);
    protected:
        int length;
        Node<type> *first;
        Node<type> *last;
    public:
        DoublyLinkedList();
        DoublyLinkedList(const Node<type> &copy);
        ~DoublyLinkedList();
        DoublyLinkedList operator=(const Node<type> &);

        void initializeList();
        int length();
        void print();
        type front();
        type back();
        void insertLast(const type &datum);
        
};
