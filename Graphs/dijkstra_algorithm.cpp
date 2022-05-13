#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

typedef pair<int,pair<int,string>> piis;



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


    int src;
    cin>>src;

    priority_queue<piis,vector<piis>,greater<piis>> q;
    vector<int> dist(n,INT_MAX);

    q.push({0,{src,to_string(src)}});
    dist[0]=0;

    while(!q.empty())
    {
        auto node = q.top();
        q.pop();

        int u=node.second.first;
        int w=node.first;
        string s=node.second.second;

        if(dist[u]<w)
        continue;

        cout<<u<<" via "<<s<<" @ "<<w<<"\n";

        for(auto x:g[u])
        {
            if(dist[x.first]>dist[u]+x.second)
            {
              dist[x.first]=dist[u]+x.second;
              q.push({dist[x.first],{x.first,s+to_string(x.first)}});
            }    
        }


    }
}