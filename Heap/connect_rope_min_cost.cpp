#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int


int getmin(vector<int>& a)
{
    priority_queue<int,vector<int>,greater<int>> p;

    for(int i=0;i<a.size();i++)
    p.push(a[i]);

    int sum=0;
    int tmp;
    while(p.size()>=2)
    {
        tmp=p.top();
        p.pop();
        tmp+=p.top();
        p.pop();
        sum+=tmp;
        p.push(tmp);

    }

    return sum;
}

int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    cout<<getmin(a);
}