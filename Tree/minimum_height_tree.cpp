#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//https://leetcode.com/problems/minimum-height-trees/

vector<int> getans(vector<int> g[],int n)
{
    vector<int> indegree(n,0);

    for(int i=0;i<n;i++)
    {
        for(auto x:g[i])
        indegree[x]++;
    }

    queue<int> q;

    for(int i=0;i<n;i++)
    {
        if(indegree[i]==1)
        q.push(i);
    }

    vector<int> ans;

    while(!q.empty())
    {
        ans.clear();
        int s=q.size();

        while(s--)
        {
            int cur=q.front();
            q.pop();
            ans.push_back(cur);
            for(auto x:g[cur])
            {
                indegree[x]--;
                if(indegree[x]==1)
                q.push(x);
            }
        }
    }

    return ans;

} 


int main()
{
    int n;
    cin>>n;

    vector<int> g[n];

    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> ans=getans(g,n);

    for(auto x:ans)
    cout<<x<<" ";
}