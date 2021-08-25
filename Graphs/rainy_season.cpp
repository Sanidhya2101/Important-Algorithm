#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

void dfs(vector<string> &s,int i,int j)
{
    if(i<0 || i>=s.size() || j<0 || j>=s[0].size() || s[i][j]!='.')
    return;

    s[i][j]='x';

    dfs(s,i+1,j);
    dfs(s,i-1,j);
    dfs(s,i,j-1);
    dfs(s,i,j+1);
}


int main()
{
    int n,m;
    cin>>n>>m;

    vector<string> s;

    for(int i=0;i<n;i++)
    {
        string p;
        cin>>p;

        s.push_back(p);
    }


    for(int i=0;i<n;i++)
    {
        if(s[i][0]=='.')
        dfs(s,i,0);
    }

    for(int i=0;i<n;i++)
    {
        if(s[i][m-1]=='.')
        dfs(s,i,m-1);
    }

    for(int j=0;j<m;j++)
    {
        if(s[0][j]=='.')
        dfs(s,0,j);
    }

    for(int j=0;j<m;j++)
    {
        if(s[n-1][j]=='.')
        dfs(s,n-1,j);
    }

    int ans=0;

    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<s[0].size();j++)
        {
            if(s[i][j]=='.')
            ans++;
        }
    }

    cout<<ans;
}