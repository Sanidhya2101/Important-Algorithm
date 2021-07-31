#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//1 2 3 4 5 6 7 8
//1 5 8 9 10 17 17 20
//8


//max

//1 2 3 4
//5 6 8 8 
//4

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);

    vector<int> w(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    for(int i=0;i<n;i++)
    cin>>w[i];

    int l;
    cin>>l;


    vector<vector<int>> dp(n+1,vector<int>(l+1));

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<l+1;j++)
        {
            if(j==0)
            dp[i][j]=0;
            else if(i==0)
            dp[i][j]=0;
            else if(a[i-1]<=j)
            dp[i][j]=max(w[i-1]+dp[i][j-a[i-1]],dp[i-1][j]);
            else
            dp[i][j]=dp[i-1][j];
        }
    }

    cout<<dp[n][l];



}