#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s,int data){
    // base case.
    if(s.empty()){
        s.push(data);
        return;
    }
    // rec case.
    int temp = s.top();
    s.pop();
    insertAtBottom(s,data); // use of recursion.
    s.push(temp);
}

void reverse(stack<int> &s){
    // base case
    if(s.empty()){
        return;
    }
    // rec case.
    int t = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s,t);
}

int main(){

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(10);

    // insertAtBottom(s,5);
    reverse(s);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}