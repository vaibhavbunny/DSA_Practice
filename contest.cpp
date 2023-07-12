#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n;cin>>n;
        string s;cin>>s;
        int maxlength = 0;
        int cureentlength = 1;
        for(int j=1;j<n;j++){
            if(s[j]==s[j-1]){
                cureentlength++;
            }else{
                maxlength = max(maxlength,cureentlength);
                cureentlength = 1;
            }
        }
        
        cout<<max(maxlength,cureentlength)+1<<endl;
    }
    return 0;
}