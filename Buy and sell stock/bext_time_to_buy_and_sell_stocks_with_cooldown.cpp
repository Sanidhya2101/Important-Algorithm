#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

int withspace(vector<int> a)
{
    int n=a.size();
    vector<vector<int>> dp(3,vector<int>(n,0));

    dp[0][0]=-a[0];

    for(int i=1;i<n;i++)
    {
        dp[0][i]=max(dp[0][i-1],dp[2][i-1]-a[i]);
        dp[1][i]=max(dp[1][i-1],dp[0][i-1]+a[i]);
        dp[2][i]=max(dp[2][i-1],dp[1][i-1]);
    } 

    return dp[1][n-1];
}

int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    cout<<withspace(a)<<" ";
    //cout<<withoutspace(a);    
}