#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int
//directed graph


bool DFS_check(int s,vector<int> a[],vector<int> &v,vector<int> &recursionstack)
{
    v[s]=1;
    recursionstack[s]=1;

    for(auto x:a[s])
    {
        if((!v[x]) && DFS_check(x,a,v,recursionstack))
        {
            return true;
        }
        else if(recursionstack[x])
        return true;

    }

    recursionstack[s]=0;
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

    vector<int> v(n+1,0);

    vector<int> recursionstack(n+1,0);

    bool flag=true;

    for(int i=1;i<=n;i++)
    {
        if(DFS_check(i,a,v,recursionstack))
        {
            flag=false;
            break;
        }
    }

    if(!flag)
    cout<<"YES";
    else
    cout<<"NO";
}