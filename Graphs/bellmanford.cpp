#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int


//O(V*E)
vector<int> bellman(vector<vector<int>> g,int src, int n,int m)
{
    vector<int> dist(n,INT_MAX);
    dist[src]=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m;j++)
        {
            int u=g[j][0];
            int v=g[j][1];
            int w=g[j][2];

            if(dist[u]!=INT_MAX && dist[v]>dist[u]+w)
            dist[v]=dist[u]+w;
        }
    }

    for(int j=0;j<m;j++)
    {
        int u=g[j][0];
        int v=g[j][1];
        int w=g[j][2];
        if(dist[v]>dist[u]+w)
        return {};
    }
    
    return dist;
}



int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> g;

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g.push_back({u,v,w});
    }

    int src;
    cin>>src;

    vector<int> ans=bellman(g,src,n,m);
    

    for(auto x:ans)
    cout<<x<<" ";

}