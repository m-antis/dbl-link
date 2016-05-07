  /* * * * * * * * * * * * * * * * * *
* File:          dbl_link.h
* Authors:       Michael Antis, Arthur Bonini
* Description:   ~ Header file for CSC 330 Project 3, Doubly Linked List
*                ~ This file contains the defined types for Doubly Linked List
*
*
*/

#ifndef DBL_LINK
#define DBL_LINK

#include <iostream>
  using namespace std;

template <class type>
struct Node {
    type datum;
    Node<type> *prev;
    Node<type> *next;
};


template <class type>
class DoublyLinkedList {
    private:
        int length;
        Node<type> *first;
        Node<type> *last;

        Node<type> *iterator;
    public:
        DoublyLinkedList();
        DoublyLinkedList(const DoublyLinkedList &copy);
        ~DoublyLinkedList();
        void operator=(const DoublyLinkedList &);
        void initializeList();   //I don't think we need this either.  Malik just uses this to set first = last = NULL and length = 0
        type getFirstItem() const;
        type getLastItem() const;
        type getItemAt(const int index);

        void prepend(const type &);
        void append(const type &);
        void destroyList();
        void destroyNode(const type &);
        bool isEmpty() const;
        int getLength() const;
        void printList();

        void moveFirst();
        void moveLast();
        void moveNext();
        void movePrev();
        bool EOF();
        void iterData(type &);
};

#endif //DBL_LINK