#include<bits/stdc++.h>
using namespace std;



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

    vector<vector<int>> dp(n,vector<int>(m,0));

    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(i==n-1 && j==m-1)
            dp[i][j]=a[i][j];
            else if(i==n-1)
            dp[i][j]=a[i][j]+dp[i][j+1];
            else if(j==m-1)
            dp[i][j]=a[i][j]+dp[i+1][j];
            else
            dp[i][j]=a[i][j]+min(dp[i+1][j],dp[i][j+1]);
        }
    }    

    cout<<dp[0][0]<<"\n";

    queue<pair<string,pair<int,int>>> q;

    q.push({"",{0,0}});

    while(!q.empty())
    {
        int i=q.front().second.first;
        int j=q.front().second.second;
        string s=q.front().first;
        q.pop();

        if(i==n-1 && j==m-1)
        cout<<s<<"\n";
        else if(i==n-1)
        q.push({s+'H',{i,j+1}});
        else if(j==m-1)
        q.push({s+'V',{i+1,j}});
        else
        {
            if(dp[i+1][j]<dp[i][j+1])
            q.push({s+'V',{i+1,j}});
            else if(dp[i+1][j]>dp[i][j+1])
            q.push({s+'H',{i,j+1}});
            else
            {
                q.push({s+'V',{i+1,j}});
                q.push({s+'H',{i,j+1}});
            }
        }
    }
}