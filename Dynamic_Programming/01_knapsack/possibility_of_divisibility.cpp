#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//4 7
//17 5 -21 15
//Yes

//4 5
//17 5 -21 15
//NO

bool ispossible(vector<int> a,vector<vector<int>> &dp,int k)
{
    dp[1][a[0]%k]=1;

    int n=a.size();

    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(dp[i-1][j])
            {
                dp[i][((j+a[i-1])%k+k)%k]=1;
                dp[i][((j+k-a[i-1])%k+k)%k]=1;
            }
        }
    }

    return dp[n][0];

}

int main()
{
    int n,k;
    cin>>n>>k;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        a[i]=abs(a[i]);
    }



    vector<vector<int>> dp(n+1,vector<int>(k,0));

    if(ispossible(a,dp,k))
    cout<<"Yes";
    else
    cout<<"NO";
}