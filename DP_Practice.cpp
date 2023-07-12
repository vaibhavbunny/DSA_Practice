#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

// subsetsum using recuision.
bool isSubsetSum(int sum,int n,int set[]){
    // base case.
    if(sum==0){
        return true;
    }else if(set[n-1]>sum){
        return isSubsetSum(sum,n-1,set);
    }else if(n==0){
        return false;
    }
    return isSubsetSum(sum,n-1,set) || isSubsetSum(sum-set[n-1],n-1,set);
}


// subsetsum using Dynamic Programming.
int dp[2000][2000];
int SubsetSum(int sum,int n,int set[]){
    if(sum==0){
        return 1;
    }if(set[n-1]>sum){
        return dp[n-1][sum] = SubsetSum(sum,n-1,set);
    }if(n<=0){
        return 0;
    }if(dp[n-1][sum]!=-1){
        return dp[n-1][sum];
    }else{
        return dp[n-1][sum] = SubsetSum(sum,n-1,set) || SubsetSum(sum,n-1,set);
    }
}

// coefficient problem,

int BinaC(int n,int r,int p){
    int dp[n+1][r+1];
    // base case.
    for(int i=0;i<=n;i++){
        for(int j=0;j<=min(i,r);j++){
            if(i==j || j==0){
                dp[i][j]=1;
            }else {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
    }
    return dp[n][r]%p;
}

// Cutting a Rod Problem.

int dp1[2000][2000];

int cutRod(int prices[],int index,int n){
    // base case.
    if(index==0){
        return n*prices[0];
    }
    if(dp[index][n]!=-1){
        return dp1[index][n];
    }
    // at any index we have 2 options either to cut the rod or not.
    int notCut = cutRod(prices,index-1,n);
    int cut = INT16_MIN;
    int rod_length = index+1;
    if(rod_length<=n){
        cut = prices[index] + cutRod(prices,index,n-rod_length);
    }

    return dp1[index][n] = max(cut,notCut);
}

// same code as above using recursion.

int rod(int prices[],int index,int n){
    // base case.
    if(index==0){
        return prices[0]*n;
    }
    int notCut1 = rod(prices,index-1,n);
    int cut1 = INT_MIN;
    int rod_length = index + 1;
    if(rod_length <= n){
        cut1 = prices[index] + rod(prices,index,n-rod_length);
    }
    return max(cut1,notCut1);
}

// Coloring Post Example.

int CountWays(int n,int k){
    int dp2[n+1];
    dp2[1] = k;
    dp2[2] = k*k;

    for(int i=3;i<=n;i++){

    }
}

// longest common subsequence problem using recursion algo.

int lcs(string s1,string s2,int m,int n){
    // base case.
    if(m==0 || n==0){
        return 0;
    }
    if(s1[m-1]==s2[n-1]){
        return 1 + lcs(s1,s2,m-1,n-1);
    }
    else{
        return max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
    }
}

// lcs problem using dp algorithm.
// we just have to store the result.

int lcs1(string s1,string s2,int m,int n){
    int arr[m+1][n+1];
    memset(arr,-1,sizeof(arr));
    // base case.
    if(m==0 || n==0){
        return 0;
    }
    if(arr[m][n]!=-1){
        return arr[m][n];
    }
    if(s1[m-1]==s2[n-1]){
        arr[m][n] = 1 + lcs1(s1,s2,m-1,n-1);
    }
    else{
        arr[m][n] = max(lcs1(s1,s2,m-1,n),lcs1(s1,s2,m,n-1));
    }
    return arr[m][n];
}

// longest increasing subsequence algorithm.

int lis1(int arr[],int n){
    int list[n];
    list[0] = 1;
    for(int i=0;i<n;i++){
        list[i] = 1;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] && list[i] < list[j] + 1 ){
                list[i] = list[j] + 1;
            }
        }
    }
    return *max_element(list,list+n);
}

int lis(int arr[],int n){
    int m = INT_MIN;
    // base case.
    if(n==0){
        return 0;
    }
    if(arr[0]<=arr[1]){
        return 1 + lis(arr,n-1);
    }
    else{
        return lis(arr,n-1);
    }
}

int main(){
    memset(dp,-1,sizeof(dp));
    memset(dp,-1,sizeof(dp1));
    int set[] = {1,5,3,7,4};
    int length[] = {1,2,3,4,5,6,7,8};
    int prices[] = {1,5,8,9,10,17,17,20};
    // cout<<maxP(length,prices,n)<<endl;
    // cout<<cutRod(prices,n-1,n);
    // cout<<BinaC(n,r,p)<<endl;
    // cout<<rod(prices,n-1,n)<<endl;
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    int m = s1.length();
    int n = s2.length();
    cout<<lcs(s1,s2,m,n)<<endl;
    cout<<lcs1(s1,s2,m,n)<<endl;
    int arr[] = {3,10,2,1,20};
    int k = 5;
    cout<<lis1(arr,k)<<endl;

    return 0;
}