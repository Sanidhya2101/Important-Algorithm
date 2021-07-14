#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

ll gcd(ll a,ll b)
{
  return a%b==0?b:gcd(b,a%b);
}

ll nCr(ll n,ll r)
{
    if(n-r<r)
    r=n-r;

    ll nu=1;
    ll d=1;

    while(r)
    {
        nu*=n;
        d*=r;

       ll tmp = gcd(nu,d);

       nu/=tmp;
       d/=tmp;

       n--;
       r--; 
    }

    return nu;
}

ll catalan_rec(ll n)// O(2^n)
{
    if(n<=1)
    return 1;

    ll res=0;

    for(int i=0;i<n;i++)
    res+=catalan_rec(i)*catalan_rec(n-i-1);

    return res;

}

ll catalan_dp(ll n)// O(n^2)
{
    vector<ll> cat(n+1);

    cat[0]=cat[1]=1;

    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        cat[i]+=cat[j]*cat[i-j-1];
    }

    return cat[n];
}

ll catalan_bin(ll n)
{
    ll c=nCr(2*n,n);

    return c/(n+1);
}

int main()
{
    ll n;
    cin>>n;

    cout<<catalan_rec(n)<<" "<<catalan_dp(n)<<" "<<catalan_bin(n)<<" ";
}