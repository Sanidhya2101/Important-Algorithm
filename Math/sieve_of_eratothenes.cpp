#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int


vector<ll> sieve(ll n)
{
    vector<ll> a(n+1,1);

    a[0]=0;
    a[1]=0;

    for(int i=2;i*i<=n;i++)
    {
        if(a[i]==1)
        {
            for(int j=i*i;j<=n;j+=i)
            a[j]=0;

        }
    }

    return a;
}



int main()
{
    ll n;
    cin>>n;

    vector<ll> a=sieve(n);

    for(int i=0;i<=n;i++)
    {
        if(a[i]==1)
        cout<<i<<" ";
    }
}