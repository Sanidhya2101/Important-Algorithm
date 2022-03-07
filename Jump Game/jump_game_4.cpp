#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//https://leetcode.com/problems/jump-game-iv/


int minstep_bfs(vector<int> a)
{
    int n=a.size();

    unordered_map<int,vector<int>> mp;

    for(int i=0;i<n;i++)
    mp[a[i]].push_back(i);

    queue<int> q;
    q.push(0);

    vector<bool> vis(n+1,0);
    vis[0]=1;

    int ans=0;

    while(!q.empty())
    {
        int m=q.size();

        while(m--)
        {
            int pos=q.front();
            q.pop();

            if(pos==n-1)
            return ans;

            vector<int> nex=mp[a[pos]];

            nex.push_back(pos-1);
            nex.push_back(pos+1);

            for(auto x:nex)
            {
                if(x>=0 && x<n && !vis[x])
                {
                    vis[x]=1;
                    q.push(x);
                }
            }
            mp[a[pos]].clear();
        }
        ans++;
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    cout<<minstep_bfs(a);    
}