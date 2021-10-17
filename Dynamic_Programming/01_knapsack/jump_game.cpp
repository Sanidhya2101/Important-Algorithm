#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//https://leetcode.com/problems/jump-game-ii/

int getans(vector<int> a)
{
    int n=a.size();

    vector<int> dp(n,INT_MAX);

    dp[0]=0;

    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<n && j<=i+a[i];j++)
        {
            if(j==n-1)
            return dp[i]+1;

            dp[j]=min(dp[i]+1,dp[j]);
        }
    }

    return -1;

}


int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<getans(a);
}