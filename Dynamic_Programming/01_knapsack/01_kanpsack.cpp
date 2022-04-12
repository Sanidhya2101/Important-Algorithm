#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int


int main()
{
    int n;
    cin>>n;

    
    vector<int> val(n);

    for(int i=0;i<n;i++)
    cin>>val[i];


    vector<int> weight(n);
    for(int i=0;i<n;i++)
    cin>>weight[i];

    int cap;
    cin>>cap;

    vector<vector<int>> dp(n+1,vector<int>(cap+1,0));

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=cap;j++)
        {
            if(i==0 || j==0)
            continue;
            else if(weight[i-1]<=j)
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i-1]]+val[i-1]);
            else
            dp[i][j]=dp[i-1][j];
        }
    }

    cout<<dp[n][cap];
}