#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

void dfs(vector<vector<int>> v,int row,int col,int tmp,vector<vector<bool>>&vis,int &ans)
{
    if(row<0||row>=v.size()||col<0||col>=v[0].size()||vis[row][col]||v[row][col]==0)
    {
        ans=max(ans,tmp);
        return;
    }

    vis[row][col]=true;
    tmp+=v[row][col];
    dfs(v,row+1,col,tmp,vis,ans);
    dfs(v,row-1,col,tmp,vis,ans);
    dfs(v,row,col+1,tmp,vis,ans);
    dfs(v,row,col-1,tmp,vis,ans);

    vis[row][col]=false;
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> v(n,vector<int>(m));
    vector<vector<bool>> vis(n,vector<bool>(m));

    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    cin>>v[i][j];

    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        dfs(v,i,j,0,vis,ans);
    }

    cout<<ans;
}