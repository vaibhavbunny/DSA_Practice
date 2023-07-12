#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            a.push_back(x);
        }
        int ans = 0;
        vector<int> pos;
        for(int i=0;i<n;i++){
            if(a[i]>0){
                ans+=1;
                pos.push_back(i);
            }
        }
        bool containsNegative = false;
        int m = pos.size();
        int lastPositiveIndex = pos[m - 1];
        if (lastPositiveIndex < n) {
            for (int i = lastPositiveIndex + 1; i < n; i++) {
                if (a[i] < 0) {
                    containsNegative = true;
                    break;
                }
            }
        }
        if(containsNegative){
            ans++;
        }
        if(a[0]>0 or a[n-1]==0){
            ans--;
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            sum = sum + abs(a[i]);
        }
        cout<<sum<<","<<ans+1<<endl;
        for(int i=0;i<pos.size();i++){
            cout<<pos[i]<<" ";
        }cout<<endl;
    }
    return 0;
}