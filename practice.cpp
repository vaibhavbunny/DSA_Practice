#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

// dynamic programming.
// binary coefficients.

int binaryC(int n,int k){
    int dp[n+1][k+1];
    int i,j;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=min(i,k);j++){ // minimum of i,k is used as to form a 2D array without it getting out oif the array.
            // base case.
            if(i==j || n==k){
                dp[i][j]=1;
            }else if(j==0){
                dp[i][j]=1;
            }
            else{
                dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
            }
        }
    }
    return dp[n][k];
}

// coins change problem using recursion.

int Ways(int coins[],int n,int sum){
    // base case.
    if(sum<0){
        return 0;
    }else if(n<=0){
        return 0;
    }else if(sum==0){
        return 1;
    }
    return Ways(coins,n,sum-coins[n-1]) + Ways(coins,n-1,sum);
}

// coins change problem using Dynamic Programing.

int coin_change(int coins[],int sum,int n){
    // form a array to store all the values from beginning.
    int dp[sum+1];
    memset(dp,0,sizeof(dp)); // inililize all the values with 0;
    dp[0] = 1;
    for(int i=0;i<n;i++){
        for(int j=coins[i];j<=sum;j++){
            dp[j] += dp[j-coins[i]];
        }
    }
    return dp[sum];
}

int main(){
    int sum=10;
    int n=4;
    int coins[4] = {2,5,3,6};
    // cout<<binaryC(n,k)<<endl;
    cout<<Ways(coins,n,sum)<<endl;
    cout<<coin_change(coins,sum,n)<<endl;
    return 0;
}