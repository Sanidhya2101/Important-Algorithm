#include<bits/stdc++.h>
using namespace std;

#define ul unsigned long int


#function to calculate nCr

ul nCr(ul n,ul r)
{
    if(n-r<r)
    r=n-r;

    ul numerator=1;
    ul denominator=1;

    if(r==0)
    return n;

    while(r)
    {
        numerator*=n;
        denominator*=r;

        ul tmp = __gcd(numerator,denominator);

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
