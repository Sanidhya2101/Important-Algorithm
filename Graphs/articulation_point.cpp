#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int



vector<int> parent;
vector<int> disc;
vector<int> low;
vector<bool> vis;
vector<bool> ap;

void dfs(int u,vector<int> g[],int t)
{
    disc[u]=low[u]=t;
    t++;
    vis[u]=1;
    int cnt=0;

    for(auto v:g[u])
    {
        if(parent[u]==v)
        continue;
        else if(vis[v])
        low[u]=min(low[u],disc[v]);
        else
        {
            parent[v]=u;
            dfs(v,g,t);
            low[u]=min(low[u],low[v]);
            if(parent[u]==-1)
            {
                if(cnt>=2)
                ap[u]=true;
            }
            else
            {
                if(low[v]>=disc[u])
                ap[u]=true;
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;

    int e;
    cin>>e;

    vector<int> g[n];

    while(e--)
    {
        int u,v;
        cin>>u>>v;

        g[u].push_back(v);
        g[v].push_back(u);

    }

    parent.resize(n,0);
    disc.resize(n,0);
    low.resize(n,0);
    vis.resize(n,false);
    ap.resize(n,false);
    parent[0]=-1;
    int t=0;
    dfs(0,g,t);
}