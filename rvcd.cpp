#include<iostream>
#include<stack>
using namespace std;

void insertatBottom(stack<int> &s,int data){
    // base case.
    if(s.empty()){
        s.push(data);
        return;
    }
    int temp = s.top();
    s.pop();
    insertatBottom(s,data);
    s.push(temp);
}

void ulta(stack<int> &s){
    // base case.
    if(s.empty()){
        return;
    }
    // rec case.
    int t = s.top();
    s.pop();
    ulta(s);
    insertatBottom(s,t);
}


int reverse(int n){
    int digit;
    stack<int> s;
    while(n > 0){
        digit = n%10;
        s.push(digit);
        n = n/10;
    }
    ulta(s);
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
}
int main(){

    int n;
    cin>>n;

    reverse(n);

    return 0;
}