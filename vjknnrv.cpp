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
        vector<int> b;
        for(int j=0;j<n;j++){
            b.push_back((n+1)-a[j]);
        }
        for(int j=0;j<n;j++){
            cout<<b[j]<<" ";
        }cout<<endl;
    }
    return 0;
}