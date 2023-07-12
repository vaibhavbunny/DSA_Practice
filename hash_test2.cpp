//File : Hashtable_test.cpp
#include<iostream>
#include "hash.h"
using namespace std;



int main(){

	Hashtable<int>  h;
	h.insert("Mango",100);
	h.insert("Apple",120);
	h.insert("Banana",140);
	h.insert("Orange",200);
	h.insert("Kiwi",210);
	h.insert("Papapya",220);
	h.insert("Litchi",30);
	h.print();
	return 0;
}