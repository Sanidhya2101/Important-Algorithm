#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int


//aebcbda

int main()
{
    string a;
    cin>>a;

    int n=a.size();
    string b;

    for(int i=n-1;i>=0;i--)
    b+=a[i];

    vector<vector<int>> dp(n+1,vector<int>(n+1));

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==0 || j==0)
            dp[i][j]=0;
            else if(a[i-1]==b[j-1])
            dp[i][j]=dp[i-1][j-1]+1;
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    cout<<n-dp[n][n];
    

}