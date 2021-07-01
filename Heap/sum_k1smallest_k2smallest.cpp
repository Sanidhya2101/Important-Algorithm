#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

int getsum(vector<int>& a,int k1,int k2)
{
    priority_queue<int> p;

    for(auto x:a)
    {
        p.push(x);

        if(p.size()>k2)
        p.pop();
    }

    int sum=0;
    int c=k2-k1-1;
    p.pop();
    while(c--)
    {
        sum+=p.top();
        p.pop();
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

    int k1,k2;

    cin>>k1>>k2;

    cout<<getsum(a,k1,k2);

}