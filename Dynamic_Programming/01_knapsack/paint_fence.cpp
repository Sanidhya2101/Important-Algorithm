#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

ll withspace(int n,int k)
{
    vector<vector<ll>> dp(3,vector<ll>(n+1,0));

    for(int i=2;i<=n;i++)
    {
        if(i==2)
        {
            dp[0][i]=k;
            dp[1][i]=k*(k-1);
            dp[2][i]=dp[0][i]+dp[1][i];
        }
        else
        {
            dp[0][i]=dp[1][i-1];
            dp[1][i]=dp[2][i-1]*(k-1);
            dp[2][i]=dp[0][i]+dp[1][i];
        }
    }

    return dp[2][n];
}

ll withoutspace(int n,int k)
{
    ll same=k;
    ll dff=k*(k-1);
    ll total=same+dff;

    for(int i=3;i<=n;i++)
    {
        same=dff;
        dff=total*(k-1);
        total=same+dff;
    }

    return total;
}


int main()
{
    ll n,k;
    cin>>n>>k;

    cout<<withspace(n,k)<<" ";
    cout<<withoutspace(n,k);
}