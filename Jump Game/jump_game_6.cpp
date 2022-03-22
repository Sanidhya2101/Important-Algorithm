#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//https://leetcode.com/problems/jump-game-vi/

int maxResult(vector<int> a,int k)
{
    int n=a.size();

    vector<int> dp(n,0);

    priority_queue<pair<int,int>> p;

    for(int i=0;i<n;i++)
    {
        int back=k;

        if(p.empty())
        dp[i]=a[i];

        else
        {
            while(!p.empty() && p.top().second<(i-k))
            p.pop();

            dp[i]=p.top().first+a[i];
        }
        p.push({dp[i],i});
    }

    return dp[n-1];
    
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


    cout<<maxResult(a,k);
}