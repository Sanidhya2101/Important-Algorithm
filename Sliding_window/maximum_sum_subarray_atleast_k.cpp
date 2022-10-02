#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

int getans(vector<int> a,int k)
{
    ll ans=INT_MIN;
    int n=a.size();
    
    ll cur=a[0];
    vector<int> maxsum(n);
    maxsum[0]=a[0];
    for(int i=1;i<n;i++)
    {
        if(cur>0)
        cur+=a[i];
        else
        cur=a[i];
        
        maxsum[i]=cur;
    }
    
    ll exactk=0;
    for(int i=0;i<k;i++)
    exactk+=a[i];
    
    if(exactk>ans)
    ans=exactk;
    
    for(int i=k;i<n;i++)
    {
        exactk+=a[i]-a[i-k];
        if(exactk>ans)
        ans=exactk;
        
        ll atleastk=exactk+maxsum[i-k];
        if(atleastk>ans)
        ans=atleastk;
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

    int k;
    cin>>k;

    cout<<getans(a,k);
}