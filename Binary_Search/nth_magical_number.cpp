#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//https://leetcode.com/problems/nth-magical-number/

int main()
{
    int n,a,b;
    cin>>n>>a>>b;

    int l=min(a,b);
    int r=n*min(a,b);

    int ans;

    while(l<=r)
    {
        int mid=l+(r-l)/2;

        if(mid/a+mid/b-(mid*__gcd(a,b))/(a*b)<n)
        l=mid+1;
        else
        {
            ans=mid;
            r=mid-1;
        }
    }

    cout<<ans;
}