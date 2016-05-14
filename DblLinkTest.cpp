//
// Created by a.bonini on 5/6/2016.
//

#include "dbl_link.h"
#include "large_int.h"

int main(){
    LargeInt li1,li2;

    cout << "1: ";
    cin >> li1;

    cout << "2: ";
    cin >> li2;

    cout<<"+: "<<li1+li2;
    cout<<"-: "<<li1-li2;
    cout<<"*: "<<li1*li2<<endl;

    cout<<"==: "<<(li1 == li2)<<endl;
    cout<<">: "<<(li1 > li2)<<endl;
    cout<<">=: "<<(li1 >= li2)<<endl;
    cout<<"<: "<<(li1 < li2)<<endl;
    cout<<"<=: "<<(li1 <= li2)<<endl;

    return 0;
};