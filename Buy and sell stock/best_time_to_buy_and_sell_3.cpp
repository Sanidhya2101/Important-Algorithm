#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    int mi=a[0];
    vector<int> x(n,0),y(n,0);
    x[0]=0;
    int td=0;

    for(int i=1;i<n;i++)
    {
        mi=min(mi,a[i]);
        td=a[i]-mi;
        x[i]=max(td,x[i-1]); 
    }    

    y[n-1]=0;
    int ma=a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        ma=max(ma,a[i]);
        td=ma-a[i];
        y[i]=max(td,y[i+1]);
    }

    int ans=0;

    for(int i=0;i<n;i++)
    {
        ans=max(ans,y[i]+x[i]);
    }

    cout<<ans;
}