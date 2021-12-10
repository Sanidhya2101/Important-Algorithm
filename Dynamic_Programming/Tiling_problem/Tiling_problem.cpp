#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//2xN matrix
//2x1 tiles can be fit

//4 - 5


int main()
{
    int n;
    cin>>n;

    vector<int> dp(n+1,0);

    dp[1]=1;
    dp[0]=0;
    dp[2]=2;

    for(int i=3;i<=n;i++)
    dp[i]=dp[i-1]+dp[i-2];

    cout<<dp[n];
}