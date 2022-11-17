#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

int lis(vector<int> a)
{
    int n=a.size();
    vector<int> dp(n,1);
    
    for(int i=1;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(a[i]>a[j])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        
            //cout<<dp[i]<<" ";
    }
    
    int ans=0;
    for(auto x:dp)
        ans=max(ans,x);
    
    return ans;

}

int lis_bs(vector<int> a)
{
    int n=a.size();
    vector<int> tmp;
    tmp.push_back(a[0]);
    for(int i=1;i<n;i++)
    {
        if(a[i]>tmp.back())
        tmp.push_back(a[i]);
        else
        {
            int ind=lower_bound(tmp.begin(),tmp.end(),a[i])-tmp.begin();
            tmp[ind]=a[i];
        }
    }

    return tmp.size();
}


int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];
}