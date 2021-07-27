#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int



int getposition(vector<int>& v,int n,int k,int in)
{
    if(v.size()==1)
    return v[0];

    in=(in+k-1)%n;

    for(int i=in;i<v.size()-1;i++)
    v[i]=v[i+1];

    v.pop_back();

    return getposition(v,n-1,k,in);
}

int getpos(int n,int k)
{
    if(n==1)
    return 1;

    int y=getpos(n-1,k);

    return (y+k-1)%(n)+1;
}

int main()
{
    int n,k;
    cin>>n>>k;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    a[i]=i+1;

    cout<<getposition(a,n,k,0)<<"\n";

    cout<<getpos(n,k);
}