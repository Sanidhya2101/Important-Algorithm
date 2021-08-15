#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

bool recur(int strt,int src,int sz,vector<int> a[],vector<int> &vis,vector<int> &path,int n)
{
    if(sz==0)
    {
        for(int i=1;i<=n;i++)
        {
            path.push_back(i);
            for(auto x:a[i])
            {
                vis[i]=1;
                vis[x]=1;
                path.push_back(x);
                bool flg=recur(i,x,sz+2,a,vis,path,n);

                if(flg)
                return true;

                vis[x]=0;
                vis[i]=0;
                path.pop_back();
            }
            path.pop_back();
        }
    }
    else
    {
        if(sz==n)
        {
            return true;
        }
        else if(sz>n)
        return false;
        
            for(auto x:a[src])
            {
                if(!vis[x])
                {
                    vis[x]=1;
                    path.push_back(x);
                    bool flg=recur(strt,x,sz+1,a,vis,path,n);
                    if(flg)
                    return true;

                    vis[x]=0;
                    path.pop_back();
                }
            }
        
    }
    
        return false;


}


int main()
{
    int n;
    cin>>n;

    vector<int> a[n+1];

    for(int i=0;i<n;i++)
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
        }
    }

    vector<int> vis(n+1,0);
    vector<int> path;
    bool flg=recur(-1,-1,0,a,vis,path,n);

    if(flg)
    {
        for(auto x:path)
        cout<<x<<" ";
    }
    else
    cout<<-1;

}