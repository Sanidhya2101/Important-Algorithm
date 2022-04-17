#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

void BFS_recusion(int s,vector<int> a[],vector<int> &v,queue<int> &q)
{
    if(q.empty())
    return;
    q.pop();

    cout<<s<<" ";

    v[s]=1;
    for(auto x:a[s])
    {
        if(!v[x])
        {
            v[x]=1;
            q.push(x);
        }
    }

    BFS_recusion(q.front(),a,v,q);
}


int main()
{
    int n;
    cin>>n;
    vector<int> a[n+1];
    vector<int> v(n+1,0);

    int p=n;
    while(p--)
    {
        int x;
        cin>>x;
        while(1)
        {
            int y;
            cin>>y;
            if(y==-1)
            break;
            a[x].push_back(y);
            a[y].push_back(x);
        }
    }


    queue<int> q; 

    for(int i=1;i<=n;i++)
    {
        q.push(i);
        if(!v[i])
        {
            BFS_recusion(i,a,v,q);
        }
    }
}