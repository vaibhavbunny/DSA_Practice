#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void inOrder(vector<int> a,vector<int> b,int n){
    // base case.
    int i = 0;
    int k = 0;
    while(a[i]+b[k]<=a[i+1]+b[k+1] && i<n-1){
        i+=1;
        k+=1;
    }
    if(i==k && k==n-1){
        return;
    }
    // rec case.
    swap(b[k],b[k+1]);
    inOrder(a,b,n);
}

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
        if(is_sorted(a.begin(),a.end()) or is_sorted(a.rbegin(),a.rend())){
            reverse(a.begin(),a.end());
            b = a;
        }else{
            b = a;
            inOrder(a,b,n);
        }
        for(int j=0;j<n;j++){
            cout<<b[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}