//
// Created by a.bonini on 5/6/2016.
//

#include "dbl_link.cpp"

int main(){
    DoublyLinkedList<int> dbl, dbl2;

    dbl.prepend(1);
    dbl.append(2);
    dbl.prepend(3);
    dbl.prepend(1);
    dbl.append(2);
    dbl.prepend(3);

    dbl2 = dbl;

    dbl2.append(122);
    dbl2.prepend(145);

    DoublyLinkedList<int> dbl3(dbl);
    dbl3.prepend(45);


    int i;

    dbl.moveFirst();
    while (!dbl.EOF()){
        dbl.iterData(i);
        cout<<i<<" ";
        dbl.moveNext();
    }
    cout<<"\n"<<dbl.getLength()<<"\n";

    dbl2.moveLast();
    while (!dbl2.EOF()){
        dbl2.iterData(i);
        cout<<i<<" ";
        dbl2.movePrev();
    }
    cout<<"\n"<<dbl2.getLength()<<"\n";

    dbl3.printList();

    return 0;
};