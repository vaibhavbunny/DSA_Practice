#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(Stack<int> &s,int data){
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

int main(){

    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(10);

    insertAtBottom(s,5);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}