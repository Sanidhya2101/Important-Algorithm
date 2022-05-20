#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//https://nados.io/question/goldmine?zen=true

int max_gold(vector<vector<int>>& a,int n,int m)
{
    vector<vector<int>> dp(n,vector<int>(m,0));

    for(int i=0;i<n;i++)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(j==m-1)
            dp[i][j]=a[i][j];
            else if(i==0)
            dp[i][j]=max(dp[i][j+1],dp[i+1][j+1])+a[i][j];
            else if(i==n-1)
            dp[i][j]=max(dp[i][j+1],dp[i-1][j+1])+a[i][j];
            else
            dp[i][j]=max({dp[i][j+1],dp[i-1][j+1],dp[i+1][j+1]})+a[i][j];
        }

    }

    int ans=0;

    for(int i=0;i<n;i++)
    ans=max(ans,dp[i][0]);

    return ans;
}


int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> a(n,vector<int>(m));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }

    cout<<max_gold(a,n,m);
}