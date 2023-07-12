#include<iostream>
#include "list.h"
using namespace std;

int main(){

    List l;
    l.push_front(1);
    l.push_front(0);
    l.push_back(3);
    l.push_back(4);
    l.insert(2,2);
    // l.pop_back();
    l.remove(3);

    Node* head = l.Begin();
    while(head!=NULL){
        cout<<head->getData()<<"->";
        head = head->next;
    }
    // otherwise
    return 0;
}