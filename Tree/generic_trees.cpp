#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

void bfs(int head,vector<int> &vis,vector<int> g[],int curr,int &ma)
{
    vis[head]=1;

    queue<pair<int,int>> q;
    q.push({head,curr});

    while(!q.empty())
    {
        pair<int,int> p=q.front();
        ma=max(ma,p.second);
        q.pop();
        for(auto x:g[p.first])
        {
            if(!vis[x])
            {
                vis[x]=1;
                bfs(x,vis,g,curr+1,ma);
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;

    vector<int> g[n+1];
    int head;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;

        if(x==-1)
        head=i;
        else
        {
            g[x].push_back(i);
            g[i].push_back(x);
        }

    }

    vector<int> vis(n+1,0);

    int ma=0;
    bfs(head,vis,g,0,ma);

    cout<<ma;
}