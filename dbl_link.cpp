#include "dbl_link.h"

template <class type>
void DoublyLinkedList<type>::prepend(const type &node) {

    if(!isEmpty()) {
        first->prev = node;
        node->next = first;
        cout << "\nNode successfully prepended"; // for testing purposes
    }
    else {
        first = node;
        last = node;
        last->next = NULL;
    }
}

template <class type>
void DoublyLinkedList<type>::append(const type &node) {

    if(!isEmpty()) {
        node->prev = last;
        node->next = NULL;
        cout << "\nNode successfully appended"; // for testing purposes

    }
    else {
        first = node;
        last = node;
        last->next = NULL;
    }

}

void append(const type &);
void destroyList();
void destroyNode(const type &);
bool isEmpty() const;
int length() const;
void printList() const;


DoublyLinkedList::
