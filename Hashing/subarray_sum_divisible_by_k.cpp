#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul long long int


int main()
{
    int n,k;
    cin>>n>>k;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    int sum=0;
    int rem;
    unordered_map<int,int> m;
    m[0]++;

    int ans=0;

    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        rem=sum%k;

        if(rem<0)
        rem+=k;

        if(m[rem])
        ans+=m[rem];

        m[rem]++;
    }

    cout<<ans;
}