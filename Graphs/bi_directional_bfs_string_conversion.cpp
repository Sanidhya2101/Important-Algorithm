#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int


bool check(string s,string p)
{
    int cnt=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=p[i])
        cnt++;
    }
    if(cnt==1)
    return 1;

    return 0;
}


int getans(string s,string e,vector<string> a)
{
    queue<pair<string,int>> q,p;
    q.push({s,1});
    p.push({e,1});


    unordered_map<string,int> vis1,vis2;
    vis1[s]=1;
    vis2[e]=1;

    while(!q.empty() && !p.empty())
    {
        pair<string,int> cur1=q.front();
        pair<string,int> cur2=p.front();

        q.pop();
        p.pop();

        for(auto x:a)
        {
            if(check(cur1.first,x) && vis1.find(x)==vis1.end())
            {
                vis1[x]=cur1.second+1;
                q.push({x,cur1.second+1});

                if(cur1.first==e)
                {
                    return cur1.second;
                }

                if(vis2.find(cur1.first)!=vis2.end())
                {
                    return cur1.second+vis2[cur1.first]-1;
                }
            }
        }

        for(auto x:a)
        {
            if(check(cur2.first,x) && vis2.find(x)==vis2.end())
            {
                vis2[x]=cur2.second+1;
                p.push({x,cur2.second+1});

                if(cur2.first==s)
                {
                    return cur2.second;
                }

                if(vis1.find(cur2.first)!=vis1.end())
                {
                    return cur2.second+vis1[cur2.first]-1;
                }
            }
        }
    }

    return 0;
}

int main()
{
    string s,e;
    cin>>s>>e;

    int n;
    cin>>n;

    vector<string> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    cout<<getans(s,e,a);

}