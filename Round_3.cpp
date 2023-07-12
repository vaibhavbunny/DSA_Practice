#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n>>k;
        vector<int> a;
        vector<int> b;
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        for(int k=0;k<n;k++){
            int y;
            cin>>y;
            b.push_back(y);
        }
        for(int m=0;m<n;m++){
            for(int l=m;l<n;l++){
                if(abs(a[m]-b[l])<=k){
                    swap(b[m],b[l]);
                }
            }
        }
        for(int j=0;j<n;j++){
            cout<<b[j]<<" ";
        }
    }
    return 0;
}