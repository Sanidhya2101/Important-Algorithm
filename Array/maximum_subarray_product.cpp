#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//https://leetcode.com/problems/maximum-product-subarray/

int max_sub_pro(vector<int> a)
{
    int ans=a[0];

    int ma=a[0];
    int mi=a[0];

    for(int i=1;i<a.size();i++)
    {
        if(a[i]<0)
        swap(ma,mi);

        ma=max(a[i],ma*a[i]);
        mi=min(a[i],mi*a[i]);

        ans=max(ans,ma);
    }

    return ans;
}


int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    cout<<max_sub_pro(a);
}