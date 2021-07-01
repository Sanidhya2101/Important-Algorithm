#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int


int getksmallest(vector<int>& a,int k)
{
    priority_queue<int> p;

    for(int i=0;i<a.size();i++)
    {
        p.push(a[i]);

        if(p.size()>k)
        p.pop();
    }

    return p.top();
}

int getklargest(vector<int>& a,int k)
{
    priority_queue<int,vector<int>,greater<int>> p;

    for(int i=0;i<a.size();i++)
    {
        p.push(a[i]);

        if(p.size()>k)
        p.pop();

    }

    return p.top();
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


    cout<<getksmallest(a,k)<<" "<<getklargest(a,k);
}