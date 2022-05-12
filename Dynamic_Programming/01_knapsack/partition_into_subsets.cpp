#include<bits/stdc++.h>
using namespace std;



int main()
{
    int n,k;
    cin>>n>>k;

    vector<vector<long>> dp(k+1,vector<long>(n+1,0));

    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            dp[i][j]=0;
            else if(i==1)
            dp[i][j]=1;
            else if(i==j)
            dp[i][j]=1;
            else if(i>j)
            dp[i][j]=0;
            else
            dp[i][j]=dp[i][j-1]*i+dp[i-1][j-1];
        }
    }

    cout<<dp[k][n];    
}