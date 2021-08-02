#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int
//axy
//adxcpy

int main()
{
    string a,b;
    cin>>a>>b;

    int n=a.size();
    int m=b.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1));

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(i==0 || j==0)
            dp[i][j]=0;
            else if(a[i-1]==b[j-1])
            dp[i][j]=dp[i-1][j-1]+1;
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

        }
    }

    if(dp[n][m]==n)
    cout<<"Yes";
    else
    cout<<"No";
}