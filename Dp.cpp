#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// Using Top Down Dp.

int fib(int n,int Dp[]){
    // base case..
    if(n==0 or n==1){
        return n;
    }
    // check bfr computing if it is being already computed.
    if(Dp[n]!=0){
        return Dp[n];
    }
    // if not computed, calculate it and store it.
    return Dp[n] = fib(n-1,Dp) + fib(n-2,Dp);
}

// Using Bottom Up Dp.

int fib2(int n){
    int Dp2[n+1];
    // base case.
    Dp2[0] = 0;
    Dp2[1] = 1;
    // iterative case.
    for(int i=2;i<=n;i++){
        Dp2[i] = Dp2[i-1]+Dp2[i-2];
    }
    return Dp2[n];
}

// using top down dp solve Coin change problem.

int minNoOfCoinsForChange(int n,vector<int> denoms){
    // base case
    if(n==0){
        return 0;
    }
    // recursive case.
    for(int c: denoms){
        minNoOfCoinsForChange(n-c,denoms);
        return min(n-c)+1;
    }
}

// using bottom up dp solve coin change problem.

int BottomUp(int m,vector<int> denoms){
    vector<int> dp(m+1,0);
    dp[0] = 0;
    for(int i=1;i<=m;i++){
        dp[i] = INT_MAX;
        for(int c : denoms){
            if(i-c>0 and dp[i-c]!=INT_MAX){
                dp[i] = min(dp[i],dp[i-c] +1);
            }
        }
    }
    return dp[m] == INT_MAX? -1 : dp[m];
}

// longest common subsequence (LCS);

int lis(vector<int> arr){
    int n = arr.size();
    vector<int> dp(n,1);

    int len = 1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i] = max(dp[i],dp[j]+1);
                len = max(dp[i],len);
            }
        }
    }
    return len;
}

// knapsack Problem Code.

int knapsack(int wt[],int price[],int n,int w){
    // base case.
    if (n==0 or w==0){
        return 0;
    }
    // recursive case.
    int inc = 0;int exc = 0;
    if(wt[n-1]<=w){
        inc = price[n-1] + knapsack(wt,price,n-1,w-wt[n-1]);
    }
    exc = knapsack(wt,price,n-1,w);
    return max(inc,exc);   
}

int knapsackDP(int wt[],int price[],int N,int W){
    vector<vector<int> > dp(N+1,vector<int>(W+1,0));

    for(int n=1;n <= N;n++){
        for(int w=1;w<=W;w++){
            int inc = 0;int exc = 0;
            if(wt[n-1] <= W){
                inc = price[n-1] + dp[n-1][W-wt[n-1]];
            }
            exc = dp[n-1][W];
            dp[N][W] = max(inc,exc);
        }
    }
    return dp[N][W];
}

//. top down approach to solve a wine problem.

int wines(int dp[][10],int prices[],int L,int R,int y){
    // base case.
    if(L>R){
        return 0;
    }
    // checking.
    if(dp[L][R]!=0){
        return dp[L][R];
    }
    // recursive case.
    int left_pick = prices[L] + wines(dp,prices,L+1,R,y+1);
    int right_pick = prices[R] + wines(dp,prices,L,R-1,y+1);
    return dp[L][R] = max(left_pick,right_pick);
}

// bottom up approach to solve a wine problem.

int BottomUp(int prices[],int n){
    vector<vector<int> > dp(n+1,vector<int>(n+1,0));

    for(int i=n-1;i>=0;i--){
        // bottom row to top row.
        for(int j=0;j<n;j++){
            if(i==j){
                dp[i][i] = n*prices[i];
            }
            else if(i<j){
                int y = n-(j-1);
                int left_pick = prices[i]*y + dp[i+1][j];
                int right_pick = prices[j]*y + dp[i][j-1];
                dp[i][j] = max(left_pick,right_pick);

                cout<<dp[i][j]<<",";
            }
            cout<<endl;
        }
    }
    return dp[0][n-1];
}

int main(){

    // vector<int> denoms = {1,3,7,10};
    // int m = 8;
    // cout<<BottomUp(m,denoms)<<endl;
    // cout<<minNoOfCoinsForChange(m,denoms)<<endl;

    // vector<int> arr = {50,4,10,8,30,100};
    // cout<<lis(arr)<<endl;
    // int wt[] = {2,7,3,4};
    // int price[] = {5,20,20,10};
    // cout<<knapsack(wt,price,4,11)<<endl;
    // cout<<knapsackDP(wt,price,4,11)<<endl;
    int a[] = {2,3,5,1,4};
    int n = 5;
    int dp[10][10] = {0};
    cout<<wines(dp,a,0,n-1,1);

    return 0;
}