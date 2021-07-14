#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int


ll gcd(ll a,ll b)
{
    return a%b==0?b:gcd(b,a%b);
}

int main()
{
    ll a,b;

    cin>>a>>b;



    cout<<gcd(a,b);
}