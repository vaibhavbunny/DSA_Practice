#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void inOrder(vector<int>& a, vector<int>& b, int n) {
    bool changed = true;
    while (changed) {
        changed = false;
        for (int j = 0; j < n - 1; j++) {
            if (a[j] + b[j] <= a[j + 1] + b[j + 1]) {
                continue;
            } else {
                swap(b[j], b[j + 1]);
                changed = true;
            }
        }
    }
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