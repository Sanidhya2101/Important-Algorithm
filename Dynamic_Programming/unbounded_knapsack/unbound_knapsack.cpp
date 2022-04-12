#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int


int main()
{
    
    int n;
    cin>>n;

    
    vector<int> val(n);

    for(int i=0;i<n;i++)
    cin>>val[i];


    vector<int> weight(n);
    for(int i=0;i<n;i++)
    cin>>weight[i];

    int cap;
    cin>>cap;


    vector<int> dp(cap+1);

    for(int j=0;j<=cap;j++)
    {
        int mx=0;
        for(int i=0;i<=n;i++)
        {
            if(weight[i-1]<=j)
            mx=max(mx,dp[j-weight[i-1]]+val[i-1]);
        }
        dp[j]=mx;
    }   

    cout<<dp[cap];
}