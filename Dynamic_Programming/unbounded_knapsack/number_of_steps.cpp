#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

vector<vector<int>> dp(100001,vector<int>(51,-1));

int getans(int n,int k)
{
    if(n==0)
    return 1;

    if(n<0)
    return 0;

    if(dp[n][k]!=-1)
    return dp[n][k];

    if(k)
    dp[n][k]=getans(n-3,k-1);

    dp[n][k]+=getans(n-1,k)+getans(n-2,k);

    return dp[n][k];

}


int main()
{
    int n,k;
    cin>>n>>k;

    cout<<getans(n,k);
}