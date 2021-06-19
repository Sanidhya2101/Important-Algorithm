//0110
//1111
//1111
//1100

#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul long long int

int MAH(vector<int>& a)
{
    stack<pair<int,int>> s;

    vector<int> ans;

    int cnt=0;

    for(int i=0;i<a.size();i++)
    {
        if(s.empty())
        {
            ans.push_back(-1);
            s.push(make_pair(a[i],i));
        }
        else if(a[i]>s.top().first)
        {
            ans.push_back(s.top().second);
            s.push(make_pair(a[i],i));
        }
        else if(a[i]<=s.top().first)
        {
            while(!s.empty() && a[i]<=s.top().first)
            s.pop();

            if(s.empty())
            ans.push_back(-1);
            else
            ans.push_back(s.top().second);

            s.push(make_pair(a[i],i));
        }
    }

    while(!s.empty())
    s.pop();

    for(int i=a.size()-1;i>=0;i--)
    {
        if(s.empty())
        {
            ans[i]=(a.size()-ans[i]-1)*a[i];
            cnt=max(cnt,ans[i]);
            s.push(make_pair(a[i],i));
        }
        else if(a[i]>s.top().first)
        {
            ans[i]=(s.top().second-ans[i]-1)*a[i];
            cnt=max(cnt,ans[i]);
            s.push(make_pair(a[i],i));
        }
        else if(a[i]<=s.top().first)
        {
            while(!s.empty() && a[i]<=s.top().first)
            s.pop();

            if(s.empty())
            ans[i]=(a.size()-ans[i]-1)*a[i];
            else
            ans[i]=(s.top().second-ans[i]-1)*a[i];

            cnt=max(ans[i],cnt);

            s.push(make_pair(a[i],i));
        }
    }

    return cnt;
}


int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> a(n,vector<int>(m));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>a[i][j];
    }

    vector<int> h(m);

    int ans=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0)
            {
                h[j]=a[i][j];
            }
            else
            {
                if(a[i][j]==0)
                h[j]=0;
                else
                h[j]+=a[i][j];
            }

        }
        
            ans=max(ans,MAH(h));
            //cout<<ans<<" ";
    }

    cout<<ans;
}