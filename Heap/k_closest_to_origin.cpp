#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

int mul(int a,int b)
{
    return a*a+b*b;
}

vector<pair<int,int>> getkclosest(vector<pair<int,int>>& a,int k)
{
    priority_queue<pair<int,pair<int,int>>> p;

    for(int i=0;i<a.size();i++)
    {
        p.push(make_pair(mul(a[i].first,a[i].second),make_pair(a[i].first,a[i].second)));

        if(p.size()>k)
        p.pop();
    }

    vector<pair<int,int>> ans;

    while(!p.empty())
    {
        ans.push_back(make_pair(p.top().second.first,p.top().second.second));
        p.pop();
    }

    return ans;

}


int main()
{
    int n;
    cin>>n;

    vector<pair<int,int>> a(n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i].first>>a[i].second;
    }

    int k;
    cin>>k;

    for(auto x:getkclosest(a,k))
    {
        cout<<x.first<<" "<<x.second<<"\n";
    }
}