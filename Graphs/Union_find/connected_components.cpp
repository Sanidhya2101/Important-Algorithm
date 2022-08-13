#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

class DisjointUnion{

    unordered_map<int,int> parent;
    unordered_map<int,int> rank;

    public:
     
    void make_set(int n)
    {
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
    }

    int Find(int x)
    {
        if(parent[x]!=x)
        parent[x]=Find(parent[x]);

        return parent[x];
    }

    void Union(int x,int y)
    {
        int lx=Find(x);
        int ly=Find(y);

        if(lx==ly)
        return;

        if(rank[lx]<rank[ly])
        parent[lx]=ly;
        else if(rank[ly]<rank[lx])
        parent[ly]=lx;
        else
        {
            parent[lx]=ly;
            rank[ly]++;
        }
    }

    int get_component(int n)
    {
        unordered_set<int> s;
        for(int i=0;i<n;i++)
        {
            //cout<<Find(parent[i])<<" ";
            s.insert(Find(parent[i]));
        }
        return s.size();
    }
};


int main()
{
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>> g;

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;

        g.push_back({u,v});
    }

    DisjointUnion dsu;

    dsu.make_set(n);

    for(auto x:g)
    {
        int u=x.first;
        int v=x.second;

        dsu.Union(u,v);
    }

    int cnt=dsu.get_component(n);

    cout<<cnt;
}