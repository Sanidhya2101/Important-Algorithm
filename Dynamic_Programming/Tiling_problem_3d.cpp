#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int
#define mod 1000000007

ll v[1000003];

ll solve(int n)
{
    if(v[n]!=-1)
    return v[n];

    v[n]=(3*solve(n-1))%mod+(3*solve(n-2)%mod)%mod-(solve(n-3))%mod;

    v[n]%=mod;

    if(v[n]<0)
    v[n]+=mod;

    return v[n];

}

int main()
{
    int n;
    cin>>n;

    memset(v,-1,sizeof(v));
    v[1]=2;
    v[2]=9;
    v[3]=32;

    cout<<solve(n)%mod;
}