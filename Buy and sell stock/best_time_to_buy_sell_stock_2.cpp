#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

int main()
{
       int n;
       cin>>n;

       vector<int> a(n);

       for(int i=0;i<n;i++)
       cin>>a[i];

       int ans=0;
       int cur=a[0];

       for(int i=1;i<n;i++)
       {
           if(a[i]>a[i-1])
           ans+=a[i]-a[i-1];
           
           cur=a[i];
       }

       cout<<ans;
}