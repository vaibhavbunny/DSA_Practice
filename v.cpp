#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T;cin>>T;
	for(int i=0;i<T;i++){
	    int N;cin>>N;
	    if(1<=N<=10){
	        cout<<"Lower double"<<endl;
	    }
	    else if(11<=N<=15){
	        cout<<"Lower Single "<<endl;
	    }else if(16<=N<=25){
	        cout<<"Upper Double"<<endl;
	    }else if(26<=N<=30){
	        cout<<"Upper Single"<<endl;
	    }
	}
	return 0;
}
