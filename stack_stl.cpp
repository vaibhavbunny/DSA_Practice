#include<iostream>
#include<stack>
using namespace std;

int main(){
    
    stack<string> books;
    books.push("vaibhav");
    books.push("shantanu");
    books.push("parth");

    while(!books.empty()){
        cout<<books.top()<<endl;
        books.pop();
    }
    return 0;

}