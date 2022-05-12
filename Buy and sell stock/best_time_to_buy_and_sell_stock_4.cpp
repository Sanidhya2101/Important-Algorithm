#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

int maxprofit(vector<int> a,int k)
{
    int n=a.size();
    if(n==0)
    return 0;

    vector<vector<int>> dp(k+1,vector<int>(n,0));

    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j]=dp[i][j-1];

            for(int k=0;k<j;k++)
            {
                dp[i][j]=max(dp[i][j],dp[i-1][k]+a[j]-a[k]);
            }
        }
    }

    return dp[k][n-1];
}

int maxprofitoptimize(vector<int> a,int k)
{
    int n=a.size();
    vector<vector<int>> dp(k+1,vector<int>(n,0));

    int ma=INT_MIN;

    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<n;j++)
        {
            ma=max(ma,dp[i-1][j-1]-a[j-1]);

            dp[i][j]=max(ma+a[j],dp[i][j-1]);
        }
    }


    return ma;
}


int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    int k;
    cin>>k;

    cout<<maxprofit(a,k)<<"\n"<<maxprofitoptimize(a,k);

}