#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//https://leetcode.com/problems/redundant-connection-ii/

class DisjointUnion{

    unordered_map<int,int> parent;
    unordered_map<int,int> rank;

    public:

    void make_set(int n)
    {
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
    }

    int Find(int x)
    {
        if(parent[x]!=x)
        {
            parent[x]=Find(parent[x]);
        }

        return parent[x];
    }

    bool Union(int x,int y)
    {
        int lx=Find(x);
        int ly=Find(y);

        if(lx==ly)
        return true;

        if(rank[lx]<rank[ly])
        parent[ly]=lx;
        else if(rank[ly]<rank[lx])
        parent[lx]=ly;
        else
        {
            parent[lx]=ly;
            rank[ly]++;
        }

        return false;
    }

};


pair<int,int> get_edge(vector<pair<int,int>> g,int n)
{
    vector<int> indeg(n+1,-1);
    int blk1=-1,blk2=-1;


    for(int i=0;i<n;i++)
    {
        int u=g[i].first;
        int v=g[i].second;

        if(indeg[v]==-1)
        indeg[v]=i;
        else
        {
            blk1=i;
            blk2=indeg[v];
            break;
        }
    }

    DisjointUnion dsu;

    dsu.make_set(n);

    for(int i=0;i<n;i++)
    {
        if(blk1==i)
        continue;

        int u=g[i].first;
        int v=g[i].second;

        bool flag=dsu.Union(u,v);

        if(flag)
        {
            if(blk1==-1)
            return {u,v};
            else
            return {g[blk2].first,g[blk2].second};
        }

    }

    return {g[blk1].first,g[blk1].second};

}


int main()
{
    int n;
    cin>>n;

    vector<pair<int,int>> g;

    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;

        g.push_back({x,y});
    }    

    pair<int,int> p=get_edge(g,n);

    cout<<p.first<<" "<<p.second;


}