#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int


int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(auto &x:a)
    {
        cin>>x;
    }

    int mi=INT_MAX;
    int ans=0;

    for(int i=0;i<n;i++)
    {
        mi=min(mi,a[i]);
        ans=max(ans,a[i]-mi);
    }

    cout<<ans;
}