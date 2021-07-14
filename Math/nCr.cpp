#include<bits/stdc++.h>
using namespace std;

#define ul unsigned long int


//function to calculate nCr

ul nCr(ul n,ul r)
{
    if(n-r<r)
    r=n-r;

    if(r==0)
    return 1;

    ul numerator=1;
    ul denominator=1;

    while(r)
    {
        numerator*=n;
        denominator*=r;

        ul tmp=__gcd(denominator,numerator);

        numerator/=tmp;
        denominator/=tmp;

        n--;
        r--;
    }

    return numerator;
}

int main()
{
    ul n,r;
    cin>>n>>r;

    cout<<nCr(n,r);
}
