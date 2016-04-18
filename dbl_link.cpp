#include "dbl_link.h"

template <class type>
DoublyLinkedList::DoublyLinkedList() {
    length = 0;
    first = last = NULL;
}

template <class type>
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList &copy){
    if (!copy.isEmpty()){
        length = 1;
        first = last = new Node<type>;
        first->next = first->prev = NULL;
        Node<type> *p = NULL;
        p = copy.first;

        do {
            last->datum = p->datum;
            if (p->next) {
                last->next = new Node<type>;
                last->next->prev = last;
                last = last->next;
                last->next = NULL;
                length++;
            }
            p = p->next;
        } while (p);
    } else{
        first = last = NULL;
        length = 0;
    }
}

template <class type>
DoublyLinkedList<type>::~DoublyLinkedList(){
    destroyList();
}

template <class type>
DoublyLinkedList& DoublyLinkedList<type>::operator=(const DoublyLinkedList<type> &original) {
    if (this != &original) {
        destroyList();

        Node<type> *p = NULL;
        p = original.first;

        while (p) {
            append(p->datum);
            p = p->next;
        }
    }
    return *this;
}

template <class type>
type DoublyLinkedList<type>::getFirstItem() const {
    return first->datum;
}

template <class type>
type DoublyLinkedList<type>::getLastItem() const {
    return last->datum;
}

template <class type>
type DoublyLinkedList<type>::getItemAt(const int index) {
    if (index<length){
        Node<type> *p = NULL;
        p = first;
        for (int i = 0; i < index; ++i) {
            p = p->next;
        }
        return p->datum;
    }    else {
        return NULL;
    }
}

template <class type>
void DoublyLinkedList<type>::prepend(const type &item) {
    Node<type> *p = NULL;
    p = new Node;
    p->datum = item;

    if(!isEmpty()) {
        first->prev = p;
        p->next = first;
        first = p;
        length++;
        cout << "\nNode successfully prepended"; // for testing purposes
    }
    else {
        first = last = p;
        last->next = NULL;
        length++;
    }
}

template <class type>
void DoublyLinkedList<type>::append(const type &item) {
    Node<type> *p = NULL;
    p = new Node;
    p->datum = item;

    if(!isEmpty()) {
        p->prev = last;
        p->next = NULL;
        last = p;
        length++;
        cout << "\nNode successfully appended"; // for testing purposes
    }
    else {
        first = last = p;
        last->next = NULL;
        length++;
    }
}

template <class type>
void DoublyLinkedList<type>::printList() {
    Node<type> *p;
    p = first;
    if(!isEmpty()) {
        while(p) {
            cout << p->datum << " ";
            p = p->next;
        }
    }
    else {
        cout << "\nList is empty. Nothing to print.";
    }
}

template <class type>
bool DoublyLinkedList<type>::isEmpty() const {
    return first == NULL;
}

template <class type>
int DoublyLinkedList<type>::getLength() const {
    return length;
}

template <class type>
void DoublyLinkedList<type>::destroyList() {

    if (!isEmpty()){
        Node<type> *p = NULL;

        while (first){
            p = first;
            first = first->next;
            delete p;
        }
        last = NULL;
        length = 0;
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
