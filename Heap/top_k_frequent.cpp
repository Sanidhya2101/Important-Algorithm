#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

typedef pair<int,int> pii;

vector<int> getkfrequent(vector<int>& a,int k)
{
    priority_queue<pii,vector<pii>,greater<pii>> p;
    unordered_map<int,int> m;

    for(int i=0;i<a.size();i++)
    {
        m[a[i]]++;
    }

    for(auto x:m)
    {
        p.push(make_pair(x.second,x.first));

        if(p.size()>k)
        p.pop();
    }

    vector<int> ans;

    while(!p.empty())
    {
        ans.push_back(p.top().second);
        p.pop();
    }

    reverse(ans.begin(),ans.end());

    return ans;
}

int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    int k;
    cin>>k;

    for(auto x:getkfrequent(a,k))
    cout<<x<<" ";

}