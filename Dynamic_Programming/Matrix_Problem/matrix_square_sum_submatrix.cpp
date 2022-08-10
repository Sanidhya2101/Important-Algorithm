#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//https://www.interviewbit.com/problems/maximum-sum-square-submatrix/

int main()
{   
    int n,B;
    cin>>n>>B;

    vector<vector<int>> a(n,vector<int>(n));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin>>a[i][j];
    }

    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=a[i-1][j-1]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }
    int ans=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i-B>=0 && j-B>=0)
            {
                ans=max(ans,dp[i][j]-dp[i-B][j]-dp[i][j-B]+dp[i-B][j-B]);
            }
        }
    }
    cout<<ans;

}