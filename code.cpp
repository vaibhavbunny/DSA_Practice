#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){

    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int d;
        cin>>d;

        string num;cin>>num;

        string yes = to_string(d) + num;
        int max_num = max(0,stoi(yes));
        for(int j=0;j<n;j++){
            string vaib = num.substr(0,j+1) + to_string(d) + num.substr(j+1,n-j-1);
            max_num = max(max_num,stoi(vaib));
        }
        cout<<max_num;
    }
    return 0;
}