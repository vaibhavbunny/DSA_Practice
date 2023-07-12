#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n;cin>>n;
        vector<int> a;
        for(int j=0;j<n;j++){
            int x;cin>>x;
            a.push_back(x);
        }
    }
    return 0;
}