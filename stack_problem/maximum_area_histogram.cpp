#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul long long int

//6 2 5 4 5 1 6

int getmax(vector<int>& a)
{
    int ans=0;

    stack<pair<int,int>> s;

    vector<int> left;

    for(int i=0;i<a.size();i++)
    {
        if(s.empty())
        {
            left.push_back(-1);
            s.push(make_pair(a[i],i));
        }
        else if(a[i]>s.top().first)
        {
            left.push_back(s.top().second);
            s.push(make_pair(a[i],i));
        }
        else if(a[i]<=s.top().first)
        {
            while(!s.empty() && a[i]<=s.top().first)
            {
                s.pop();
            }

            if(s.empty())
            left.push_back(-1);
            else
            left.push_back(s.top().second);

            s.push(make_pair(a[i],i));
        }
    }


    while(!s.empty())
    s.pop();

    for(int i=a.size()-1;i>=0;i--)
    {
        if(s.empty())
        {
            left[i]=(a.size()-left[i]-1)*a[i];
            ans=max(ans,left[i]);
            s.push(make_pair(a[i],i));           
        }
        else if(a[i]>s.top().first)
        {
            left[i]=(s.top().second-left[i]-1)*a[i];
            ans=max(ans,left[i]);
            s.push(make_pair(a[i],i));
        }
        else if(a[i]<=s.top().first)
        {
            while(!s.empty() && a[i]<=s.top().first)
            {
                s.pop();
            }

            if(s.empty())
            left[i]=(a.size()-left[i]-1)*a[i];
            else
            left[i]=(s.top().second-left[i]-1)*a[i];

            ans=max(ans,left[i]);

            s.push(make_pair(a[i],i));
        }
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

    cout<<getmax(a);
}