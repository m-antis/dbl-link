#include "dbl_link.h"


DoublyLinkedList::DoublyLinkedList() {
    length = 0;
    first = last = NULL;
}

template <class type>
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList &copy){
    if (!copy.isEmpty()){
        length=1;
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
    }
}

template <class type>
DoublyLinkedList::~DoublyLinkedList(){
    destroyList();
}


bool DoublyLinkedList::isEmpty() const {
    return first == NULL;
}

int DoublyLinkedList::getLength() const {
    return length;
}

template <class type>
void DoublyLinkedList::destroyList() {
    if (!isEmpty()){
        Node<type> *p = NULL;

        while (first!=NULL){
            p = first;
            first=first->next;
            delete p;
        }
        last = NULL;
        length=0;
    }
}