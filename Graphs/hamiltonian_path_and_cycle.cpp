#include<bits/stdc++.h>
using namespace std;

void hamiltonian_path(vector<int> g[],int src,unordered_set<int> &vis,string s,int osrc,int sz)
{
    if(vis.size()==sz-1)
    {
        cout<<s;

        for(auto x:g[src])
        {
            if(x==osrc)
            {
                cout<<"*\n";
                return;
            }
        }

        cout<<".\n";
    }

    vis.insert(src);

    for(auto x:g[src])
    {
        if(vis.find(x)==vis.end())
        hamiltonian_path(g,x,vis,s+to_string(x),osrc,sz);
    }

    vis.erase(src);
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
        g[y].push_back(x);
    }    

    int src;
    cin>>src;

    unordered_set<int> vis;

    hamiltonian_path(g,src,vis,to_string(src),src,n);
}