#include <iostream>
#include <vector>
#include <algorithm>  // Added header for sort()
using namespace std;

int main() {
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            arr.push_back(x);
        }
        sort(arr,arr+n);
        int nas = 0;
        for(int i=0;i<n;i++){
            int sub = arr[n-i-1]-arr[i];
            nas = nas + sub;
        }
        cout<<nas<<endl;
    }
    return 0;
}
