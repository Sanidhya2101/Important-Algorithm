#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul long long int


vector<int> getsmaller(vector<int>& a)
{
    vector<int> ans;
    
    stack<pair<int,int>> s;

    for(int i=0;i<a.size();i++)
    {
        if(s.empty())
        {
            ans.push_back(-1);
            s.push(make_pair(a[i],0));
        }
        else if(a[i]<s.top().first)
        {
            ans.push_back(s.top().second);
            s.push(make_pair(a[i],i));
        }
        else if(a[i]>=s.top().first)
        {
            while(!s.empty() && s.top().first<=a[i])
            {
                s.pop();
            }
            if(s.empty())
            ans.push_back(-1);
            else
            ans.push_back(s.top().second);


            s.push(make_pair(a[i],i));
        }
    }

    for(int i=0;i<ans.size();i++)
    ans[i]=i-ans[i];

    return ans;
}

int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    vector<int> ans=getsmaller(a);

    for(auto x:ans)
    cout<<x<<" ";
}