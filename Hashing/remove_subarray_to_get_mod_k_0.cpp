#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//3 1 4 2   6
//3 6 7 1   9

int getans(vector<int> a,int rem,int k)
{
    unordered_map<int,int> mp;

    mp[0]=-1;

    int curr=0;

    int ans=INT_MAX;

    for(int i=0;i<a.size();i++)
    {
        curr=(curr+a[i]+k)%k;

        mp[curr]=i;

        int r=(curr-rem+k)%k;

        if(mp.find(r)!=mp.end())
        ans=min(ans,i-mp[r]);
    }

    if(ans==INT_MAX || ans==a.size())
    return -1;

    return ans;
}


int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    int sum=0;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }

    int k;
    cin>>k;

    int rem=(sum+k)%k;

    if(rem==0)
    cout<<0;
    else
    cout<<getans(a,rem,k);

}