#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    int f;
    cin>>f;

    vector<vector<int>> dp(2,vector<int>(n,0));

    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            dp[0][i]=-a[i];
            dp[1][i]=0;
        }
        else
        {
            dp[0][i]=max(dp[0][i-1],dp[1][i-1]-a[i]);
            dp[1][i]=max(dp[1][i-1],dp[0][i-1]+a[i]-f);
        }
    }

    cout<<dp[1][n-1];
}