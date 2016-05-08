#include "dbl_link.h"

template <class type>
DoublyLinkedList<type>::DoublyLinkedList() {
    length = 0;
    first = last = iterator = NULL;
}

template <class type>
DoublyLinkedList<type>::DoublyLinkedList(const DoublyLinkedList &copy){
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
    iterator = NULL;
}

template <class type>
DoublyLinkedList<type>::~DoublyLinkedList(){
    destroyList();
}

template <class type>
void DoublyLinkedList<type>::operator=(const DoublyLinkedList<type> &original) {
    if (this != &original) {
        destroyList();

        Node<type> *p = NULL;
        p = original.first;

        while (p) {
            append(p->datum);
            p = p->next;
        }
    }
    iterator = NULL;
}

template <class type>
void DoublyLinkedList<type>::prepend(const type &item) {
    Node<type> *p = NULL;
    p = new Node<type>;
    p->datum = item;
    p->next = p->prev = NULL;

    if(!isEmpty()) {
        first->prev = p;
        p->next = first;
        first = p;
        length++;
        cout << "\nNode successfully prepended\n"; // for testing purposes
    }
    else {
        first = last = p;
        length++;
    }
}

template <class type>
void DoublyLinkedList<type>::append(const type &item) {
    Node<type> *p = NULL;
    p = new Node<type>;
    p->datum = item;
    p->next = p->prev = NULL;

    if(!isEmpty()) {
        p->prev = last;
        last->next = p;
        last = p;
        length++;
        cout << "\nNode successfully appended\n"; // for testing purposes
    }
    else {
        first = last = p;
        length++;
    }
}

template <class type>
void DoublyLinkedList<type>::printList() {
    Node<type> *p;
    p = first;
    if(!isEmpty()) {
        while(p != NULL) {
            cout << p->datum << " ";
            p = p-> next;
        }
    }
    else {
        cout << "\nList is empty. Nothing to print.\n";
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
    delete iterator;
}

template <class type>
void DoublyLinkedList<type>::moveFirst() {
    iterator = first;
}

template <class type>
void DoublyLinkedList<type>::moveLast() {
    iterator = last;
}

template <class type>
void DoublyLinkedList<type>::moveNext() {
    if (!EOF())
        iterator = iterator->next;
}

template <class type>
void DoublyLinkedList<type>::movePrev() {
    if (!EOF())
        iterator = iterator->prev;
}

template <class type>
bool DoublyLinkedList<type>::EOF() {
    return iterator == NULL;
}

template <class type>
void DoublyLinkedList<type>::iterData(type &data){
    if (!EOF()){
        data = iterator->datum;
    }
}