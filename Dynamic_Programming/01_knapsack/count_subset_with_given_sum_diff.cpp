#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

// 1 1 2 3
//1
//ans=3

int main()
{
    int n;
    cin>>n;

    vector<int> a(n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    int k;
    cin>>k;

    sum=(sum+k)/2;

    vector<vector<int>> dp(n+1,vector<int>(sum+1));

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(j==0)
            dp[i][j]=1;
            else if(i==0)
            dp[i][j]=0;
            else if(a[i-1]<=j)
            dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i-1]];
            else
            dp[i][j]=dp[i-1][j];
        }
    }

    cout<<dp[n][sum];

}