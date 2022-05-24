#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//https://nados.io/question/goldmine?zen=true

void max_gold(vector<vector<int>>& a,int n,int m)
{
    vector<vector<int>> dp(n,vector<int>(m,0));

    for(int j=m-1;j>=0;j--)
    {
        for(int i=0;i<n;i++)
        {
        
            if(j==m-1)
            dp[i][j]=a[i][j];
            else if(i==0)
            dp[i][j]=max(dp[i][j+1],dp[i+1][j+1])+a[i][j];
            else if(i==n-1)
            dp[i][j]=max(dp[i][j+1],dp[i-1][j+1])+a[i][j];
            else
            dp[i][j]=max({dp[i][j+1],dp[i-1][j+1],dp[i+1][j+1]})+a[i][j];
        }

    }

    int ans=0;

    queue<pair<string,pair<int,int>>> q;

    for(int i=0;i<n;i++)
    ans=max(ans,dp[i][0]);

    cout<<ans<<"\n";

    for(int i=0;i<n;i++)
    {
        if(ans==dp[i][0])
        q.push({to_string(i)+"",{i,0}});
    }

    while(!q.empty())
    {
        int i=q.front().second.first;
        int j=q.front().second.second;
        string s=q.front().first;

        q.pop();

        if(j==m-1)
        cout<<s<<"\n";
        else if(i==0)
        {
            int g=max(dp[i+1][j+1],dp[i][j+1]);

            if(g==dp[i+1][j+1])
            q.push({s+" d3",{i+1,j+1}});
            if(g==dp[i][j+1])
            q.push({s+" d2",{i,j+1}});
        }
        else if(i==n-1)
        {
            int g=max(dp[i-1][j+1],dp[i][j+1]);

            if(g==dp[i-1][j+1])
            q.push({s+" d1",{i-1,j+1}});
            if(g==dp[i][j+1])
            q.push({s+" d2",{i,j+1}});
        }
        else
        {
            int g=max({dp[i+1][j+1],dp[i][j+1],dp[i-1][j+1]});

            if(g==dp[i+1][j+1])
            q.push({s+" d3",{i+1,j+1}});
            if(g==dp[i][j+1])
            q.push({s+" d2",{i,j+1}});
            if(g==dp[i-1][j+1])
            q.push({s+" d1",{i-1,j+1}});
        }
        
        
    }
}


int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> a(n,vector<int>(m));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }

    max_gold(a,n,m);
}