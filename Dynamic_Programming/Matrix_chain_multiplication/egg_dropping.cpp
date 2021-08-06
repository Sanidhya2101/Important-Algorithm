#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int


vector<vector<int>> dp(1001,vector<int>(1001,-1));
 
int getfloor(int f,int e)
{
    if(f==0 || f==1)
    return f;

    if(e==1)
    return f;

    if(dp[f][e]!=-1)
    return dp[f][e];

    int ans=INT_MAX;

    for(int k=1;k<=f;k++)
    {
        int l,h;
        if(dp[f-1][e-1]!=-1)
        l=dp[f-1][e-1];
        else
        dp[f-1][e-1]=l=getfloor(f-1,e-1);

        if(dp[f-k][e]!=-1)
        h=dp[f-k][e];
        else
        dp[f-k][e]=h=getfloor(f-k,e);

        ans=min(ans,max(l,h));
    }

    return dp[f][e]=ans;
}

int main()
{
    int n;
    cin>>n;

    int k;
    cin>>k;

    cout<<getfloor(n,k);

}