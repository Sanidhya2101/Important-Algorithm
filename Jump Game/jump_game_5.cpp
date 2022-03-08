#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//https://leetcode.com/problems/jump-game-v/
vector<int> dp;


int maxJumps(vector<int> a,int d,int i)
{
    if(dp[i]!=-1)
    return dp[i];

    int cur=1;

    for(int j=i+1;j<=min(i+d,(int)a.size()-1);j++)
    {
        if(a[i]>a[j])
        cur=max(cur,1+maxJumps(a,d,j));
        else
        break;
    }

    for(int j=i-1;j>=max(i-d,0);j--)
    {
        if(a[i]>a[j])
        cur=max(cur,1+maxJumps(a,d,j));
        else
        break;
    }

    return dp[i]=cur;

}


int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    int d;
    cin>>d;


    dp.assign(a.size(),-1);

    int ans=1;

    for(int i=0;i<a.size();i++)
    {
        ans=max(ans,maxJumps(a,d,i));
    }

    cout<<ans;
}