#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//https://leetcode.com/problems/jump-game-ii/

int getans(vector<int> a)
{
    int n=a.size();

    if(n==1)
    return 0;

    vector<int> dp(n,INT_MAX);

    dp[0]=0;

    for(int i=0;i<n;i++)
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


int getminpath(vector<int> a)
{
    int n=a.size();
    vector<int> dp(n+1,INT_MAX);
    dp[n]=0;

    for(int i=n-1;i>=0;i--)
    {
        if(a[i]!=0)
        {
            int mi=INT_MAX;
            for(int j=1;j<=a[i] && j+i<n+1;j++)
            {
                if(dp[i+j]!=INT_MAX)
                mi=min(mi,dp[i+j]);
            }

            if(mi!=INT_MAX)
            dp[i]=mi+1;
            else
            dp[i]=INT_MAX;
        }
    }

    return dp[0];
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

    cout<<getans(a)<<" "<<getminpath(a);
}