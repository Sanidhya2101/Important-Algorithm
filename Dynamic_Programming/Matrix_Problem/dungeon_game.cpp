#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//-2 -3 3
//-5 -10 1
//10 30 -5

//return minimum hp.

//https://leetcode.com/problems/dungeon-game/

vector<vector<int>> dpm(201,vector<int>(201,-1));

int memoization(int i,int j,vector<vector<int>> &a,int n,int m)
{
    if(i>=n || j>=m)
    return INT_MAX;

    if(i==n-1 && j==m-1)
    return a[i][j]<=0?abs(a[i][j])+1:1;

    if(dpm[i][j]!=-1)
    return dpm[i][j];

    int right = memoization(i,j+1,a,n,m);

    int down = memoization(i+1,j,a,n,m);

    int ans = min(right,down)-a[i][j];

    return dpm[i][j]=ans<=0?1:ans;
}

int bottom_up_dp(vector<vector<int>> a)
{
    int n=a.size();
    int m=a[0].size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(i==n-1 && j==m-1)
            dp[i][j]=min(0,a[i][j]);
            else if(i==n-1)
            dp[i][j]=min(0,dp[i][j+1]+a[i][j]);
            else if(j==m-1)
            dp[i][j]=min(0,a[i][j]+dp[i+1][j]);
            else
            dp[i][j]=min(0,a[i][j]+max(dp[i+1][j],dp[i][j+1]));
        }
    }

    return abs(dp[0][0])+1;
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


    cout<<memoization(0,0,a,n,m)<<"\n";
    cout<<bottom_up_dp(a);
}