#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int> a;
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        sort(a.begin(),a.end());
        int ans = 0;
        int j=0;
        while(a[j]%2==0 and j<n){
            ans+=1;
            j+=1;
        }
        // all even
        if(ans == n or a[0]%2==1){
            cout<<"YES"<<" ";
        }else if(a[0]%2==0){
            for(int k=1;k<n;k++){
                if(a[k]%2==1){
                    cout<<"NO"<<" ";
                    break;
                }
            }
        }
    }
    
    return 0;
}

