#include<bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,int>> piii;

int main()
{
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>> g[n];

    while(m--)
    {
        int x,y,w;
        cin>>x>>y>>w;

        g[x].push_back({y,w});
        g[y].push_back({x,w});
    }
    
    priority_queue<piii,vector<piii>,greater<piii>> p;

    p.push({0,{0,-1}});
    
    vector<bool> vis(n,false);

    while(!p.empty())
    {
        auto node=p.top();
        p.pop();

        int u=node.second.first;
        int v=node.second.second;
        int w=node.first;

        if(vis[u])
        continue;

        vis[u]=1;

        if(v!=-1)
        cout<<"["<<u<<"-"<<v<<"@"<<w<<"]\n";

        for(auto x:g[u])
        {
            if(!vis[x.first])
            {
                p.push({x.second,{x.first,u}});
            }
        }
    }
}