#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n;cin>>n;
        vector<int> a;
        vector<int> b;
        for(int j=0;j<n;j++){
            int x;cin>>x;
            a.push_back(x);
        }
        for(int k=0;k<n;k++){
            int x;cin>>x;
            b.push_back(x);
        }
        int output = 0;
        set<int> c;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                c.insert(b[j]);
                if(a[i]*a[j]==b[i]+b[j]){
                    output+=1;
                }
            }
        }
        cout<<output<<endl;
    }
    return 0;
}