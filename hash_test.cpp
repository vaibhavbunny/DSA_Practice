#include<iostream>
#include<string>
#include "Hashtable.h"
using namespace std;

int main(){
    Hashtable<int> h;
    h.insert("mango",100);
    h.insert("apple",200);
    h.insert("guava",300);
    h.insert("papaya",400);
    h.print();

    string fruit;cin>>fruit;

    int *price = h.search(fruit);
    if(price!=NULL){
        cout<<"Price of fruit is "<<*price<<endl;
    }else{
        cout<<" fruit is not present "<<endl;
    }

    h["newfruit"] = 200;
    cout<<"Cost of newfruit "<<h["newfruit"]<<endl;
    h["newfruit"] += 20;
    cout<<"updated cost of newfruit "<<h["newfruit"]<<endl;
    

    return 0;
}