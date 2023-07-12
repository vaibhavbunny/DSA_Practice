#include<iostream>
#include<algorithm>
#include "queue.h"
#include<queue>
using namespace std;

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.pop();
    q.pop();
    q.push(9);

    while(!q.empty()){
        cout<<q.front()<<",";
        q.pop();
    }

    return 0;
}