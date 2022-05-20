#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> g[],int n)
{
    vector<int> indeg(n,0);

    for(int i=0;i<n;i++)
    {
        for(auto x:g[i])
        {
            indeg[x]++;
        }
    }

    queue<int> q;

    for(int i=0;i<n;i++)
    {
        if(indeg[i]==0)
        q.push(i);
    }

    vector<int> ans;

    while(!q.empty())
    {
        int p=q.front();
        q.pop();


        ans.push_back(p);

        for(auto x:g[p])
        {
            indeg[x]--;
            if(indeg[x]==0)
            q.push(x);
        }
    }

    for(int i=n-1;i>=0;i--)
    cout<<ans[i]<<"\n";

}

void dfs(int i,vector<int> g[],vector<bool> &vis,stack<int> &s)
{
    vis[i]=1;

    for(auto x:g[i])
    {
        if(!vis[x])
        dfs(x,g,vis,s);
    }
    s.push(i);
}


int main()
{
    int n,m;
    cin>>n>>m;

    vector<int> g[n];

    while(m--)
    {
        int x,y;
        cin>>x>>y;

        g[x].push_back(y);
    }    

    bfs(g,n);

    vector<bool> vis(n,0);
    stack<int> s;

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        dfs(i,g,vis,s);
    }

    while(!s.empty())
    {
        cout<<s.top()<<"\n";
        s.pop();
    } 
}