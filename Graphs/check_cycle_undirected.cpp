#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

bool dfs(int node,int parent,vector<int> g[],vector<bool> &vis)
{
    vis[node]=1;

    for(auto x:g[node])
    {
        if(!vis[x])
        {
            if(dfs(x,node,g,vis))
            return true;
        }
        else if(x!=parent)
        return true;
    }

    return false;
}


int main()
{
    int n,m;
    cin>>n>>m;

    vector<int> g[n];

    while(m--)
    {
        int x,y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<bool> vis(n,false);

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,-1,g,vis))
            {
                cout<<"YES";
                return 0;
            }
        }
    }

    cout<<"NO";
}