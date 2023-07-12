#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
// stock span soln.
int span(int arr[],int n){
    vector<int> s;
    for(int i=0;i<n;i++){
        int digit = 0;
        for(int j=0;j<i+1;j++){
            if(arr[j]<=arr[i]){
                digit += 1;
            }
        }s.push_back(digit);
    }
    for(int i=0;i<n;i++){
        cout<<s[i]<<",";
    }
}
// using stack data structure.
char reverse(int n){
    string yes = to_string(n);
    stack<char> s;
    for(int i=0;i<yes.size();i++){
        s.push(yes[i]);
    }
    for(int i=0;i<yes.size();i++){
        cout<<s.top();
        s.pop();
    }
}
// next greater element.
int nxtG(int arr[]){
    for(int i=0;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[i]>)
        }
    }
}
int main(){

    int arr[7] = {4,5,2,25};
    int n = sizeof(arr)/sizeof(int);

    return 0;
}