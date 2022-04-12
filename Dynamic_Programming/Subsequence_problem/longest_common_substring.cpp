#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int


int main()
{
    string a,b;
    cin>>a>>b;

    //abcde
    //abfce

    //2

    int n=a.size();
    int m=b.size();
    int ans=0;

    vector<vector<int>> dp(n+1,vector<int>(m+1));

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(i==0 || j==0)
            dp[i][j]=0;
            else if(a[i-1]==b[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=0;

            ans=max(ans,dp[i][j]);
        }
    }

    cout<<ans;

}