#include "dbl_link.h"

template <class type>
void DoublyLinkedList<type>::prepend(const type &node) {

    if(!isEmpty()) {
        first->prev = node;
        node->next = first;
        length++;
        cout << "\nNode successfully prepended"; // for testing purposes
    }
    else {
        first = node;
        last = node;
        last->next = NULL;
        length++;
    }
}

template <class type>
void DoublyLinkedList<type>::append(const type &node) {

    if(!isEmpty()) {
        node->prev = last;
        node->next = NULL;
        length++;
        cout << "\nNode successfully appended"; // for testing purposes
    }
    else {
        first = node;
        last = node;
        last->next = NULL;
        length++;
    }
}

template<class type>
void DoublyLinkedList<type>::destroyList() {
    first = last = NULL;
    length = 0;
}

template <class type>
void DoublyLinkedList<type>::printList() {
    Node<type> *p;
    p = first;
    if(!isEmpty()) {
        while(p) {
            cout << p->datum;
            p = p->next;
        }
    }
    else {
        cout << "\nList is empty. Nothing to print."
    }
}

// template<class type>
// void DoublyLinkedList<type>::destroyNode(const type &item) {
//
//     Node<type> *p;
//     p = first;
//
//     while(p) {
//         if(p->datum == item) {
//
//         }
//         p = p->next;
//     }
// }





bool isEmpty() const;
int length() const;
void printList() const;
