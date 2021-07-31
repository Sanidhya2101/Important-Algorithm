#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//1 2 3
//4
//4


//2 5 3 6
//10
//5

int getmaxchange(vector<int> &a,int w)
{
    int n=a.size();
    vector<vector<int>> dp(n+1,vector<int>(w+1));

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<w+1;j++)
        {
            if(j==0)
            dp[i][j]=1;
            else if(i==0)
            dp[i][j]=0;
            else if(a[i-1]<=j)
            {
                dp[i][j] = dp[i][j-a[i-1]]+dp[i-1][j];
            }
            else
            dp[i][j]=dp[i-1][j];
        }
    }

    return dp[n][w];
}

int min_of_coins(vector<int> a,int w)
{
    int n=a.size();

    vector<vector<int>> dp(n+1,vector<int>(w+1));

    for(int j=0;j<w+1;j++)
    dp[0][j]=INT_MAX-1;

    for(int i=1;i<n+1;i++)
    dp[i][0]=0;

    for(int j=1;j<w+1;j++)
    {
        if(j%a[0])
        dp[1][j]=INT_MAX-1;
        else
        dp[1][j]=j/a[0];
    }


    for(int i=2;i<n+1;i++)
    {
        for(int j=1;j<w+1;j++)
        {
            if(a[i-1]<=j)
            dp[i][j]=min(dp[i][j-a[i-1]]+1,dp[i-1][j]);
            else
            dp[i][j]=dp[i-1][j];
        }
    }

    return dp[n][w];
}


int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    int w;
    cin>>w;

    cout<<getmaxchange(a,w)<<"\n";
    cout<<min_of_coins(a,w);
}