#include<bits/stdc++.h>
using namespace std;

/*
1. You are given a graph, a src vertex and a destination vertex.
2. You are give a number named "criteria" and a number "k".
3. You are required to find and print the values of 
3.1 Smallest path and it's weight separated by an "@"
3.2 Largest path and it's weight separated by an "@"
3.3 Just Larger path (than criteria in terms of weight) and it's weight separated by an "@"
3.4 Just smaller path (than criteria in terms of weight) and it's weight separated by an "@"
3.5 Kth largest path and it's weight separated by an "@"
*/



string smallest_path;
int smallest_wt=INT_MAX;

string largest_path;
int largest_wt=INT_MIN;

string just_largest_path;
int just_largest_wt=INT_MAX;

string just_smallest_path;
int just_smallest_wt=INT_MIN;

priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> p;



void dfs(vector<pair<int,int>> g[],int s,int d,vector<bool> &vis,int criteria,int k,string psf,int wsf)
{
    if(s==d)
    {
        if(wsf<smallest_wt)
        {
            smallest_wt=wsf;
            smallest_path=psf;
        }
        if(wsf>largest_wt)
        {
            largest_wt=wsf;
            largest_path=psf;
        }
        if(wsf<criteria && wsf>just_smallest_wt)
        {
            just_smallest_wt=wsf;
            just_smallest_path=psf;
        }
        if(wsf>criteria && wsf<just_largest_wt)
        {
            just_largest_wt=wsf;
            just_largest_path=psf;
        }

        p.push({wsf,psf});

        if(p.size()>k)
        p.pop();

        return;
    }

    vis[s]=1;

    for(auto x:g[s])
    {
        if(!vis[x.first])
        dfs(g,x.first,d,vis,criteria,k,psf+to_string(x.first),wsf+x.second);
    }

    vis[s]=0;
}


int main()
{
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>> g[n];

    while(m--)
    {
        int x,y,w;
        cin>>x>>y>>w;

        g[x].push_back({y,w});
        g[y].push_back({x,w});
    }

    vector<bool> vis(n,0);

    int src,dest;
    cin>>src>>dest;

    int criteria,k;
    cin>>criteria>>k;

    dfs(g,src,dest,vis,criteria,k,""+to_string(src),0);


    cout << "Smallest Path = " << smallest_path << "@" << smallest_wt << endl;
    cout << "Largest Path = " << largest_path << "@" << largest_wt << endl;
    cout << "Just Larger Path than " << criteria << " = " << just_largest_path << "@" << just_largest_wt << endl;
    cout << "Just Smaller Path than " << criteria << " = " << just_smallest_path << "@" << just_smallest_wt << endl;
    cout << k << "th largest path = " << p.top().second << "@" << p.top().first << endl;
}