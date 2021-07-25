#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int


bool BFS(int s,vector<int> a[],vector<int> &v,vector<int> &c)
{
    queue<int> q;
    q.push(s);
    v[s]=1;
    c[s]=0;

    while(!q.empty())
    {
        s=q.front();
        q.pop();

        for(auto x:a[s])
        {
            if(!v[x])
            {
                v[x]=1;
                c[x]=1-c[s];
                q.push(x);
            }
            if(v[x] && c[x]==c[s])
            return false;
        }
    }

    return true;
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<int> a[n+1];

    while(m--)
    {
        int x,y;
        cin>>x>>y;

        a[x].push_back(y);
        a[y].push_back(x);
    }

    vector<int> v(n+1,0);
    vector<int> c(n+1,0);

    bool res=true;

    for(int i=1;i<=n;i++)
    {
        if(!v[i])
        res&=BFS(i,a,v,c);
    }

    if(res)
    cout<<"Yes";
    else
    cout<<"No";
}