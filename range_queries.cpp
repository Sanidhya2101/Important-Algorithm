#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    int len=ceil(sqrt(n));
    vector<int> da(len,INT_MAX);
    for(int i=0;i<n;i++)
    {
        da[i/len]=min(da[i/len],a[i]);
    }
    
    //for(int i=0;i<da.size();i++)
    //cout<<da[i]<<" ";
    //
    
    int q;
    cin>>q;
    
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        int ans=a[l];
        
        while(l<=r)
        {
            if(l%len==0 && l+len-1<=r)
            {
                ans=min(ans,da[l/len]);
                l+=len;
            }
            else
            {
                ans=min(ans,a[l]);
                l++;
            }
        }
        cout<<ans<<"\n";
    }
}