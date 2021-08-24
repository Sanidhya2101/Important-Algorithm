#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int


void dfs(vector<vector<int>> a,int i,int j,vector<vector<int>> &vis,int w)
{
    if(i<0 || j<0 || i>=a.size() || j>=a[0].size() || !a[i][j] || vis[i][j])
    return;

    vis[i][j]=1;

    if(w==1)
    {
        dfs(a,i,j+1,vis,w);
        dfs(a,i,j-1,vis,w);
    }
    else if(w==2)
    {
        dfs(a,i+1,j,vis,w);
        dfs(a,i-1,j,vis,w);
    }
    else if(w==3)
    {
        dfs(a,i+1,j+1,vis,w);
        dfs(a,i+1,j-1,vis,w);
        dfs(a,i-1,j+1,vis,w);
        dfs(a,i-1,j-1,vis,w);
    }
    else if(w==4)
    {
        
        dfs(a,i,j+1,vis,w);
        dfs(a,i,j-1,vis,w);
        dfs(a,i+1,j,vis,w);
        dfs(a,i-1,j,vis,w);
   }
   else if(w==5)
   {
        
        dfs(a,i+1,j+1,vis,w);
        dfs(a,i+1,j-1,vis,w);
        dfs(a,i-1,j+1,vis,w);
        dfs(a,i-1,j-1,vis,w);  
        
        dfs(a,i,j+1,vis,w);
        dfs(a,i,j-1,vis,w);
        dfs(a,i+1,j,vis,w);
        dfs(a,i-1,j,vis,w); 
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
        cin>>a[i][j];
    }

    for(int k=1;k<=5;k++)
    {
        int cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j] && !vis[i][j])
                {
                    dfs(a,i,j,vis,k);
                    cnt++;
                }
            }
        }

        cout<<cnt<<" ";
    }



}