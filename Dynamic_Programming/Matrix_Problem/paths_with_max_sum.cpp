#include<bits/stdc++.h>
using namespace std;

//E12
//1X1
//21S

int mod = 1e9+7;

vector<int> pathswithmaxscore(vector<string> a)
{
    int n=a.size();
    int m=a[0].size();
    vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(m,{0,0}));

    dp[n-1][m-1]={0,1};

    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            int val=0;
            if(a[i][j]!='S' && a[i][j]!='E' && a[i][j]!='X')
            val=a[i][j]-'0';
            if(i==n-1 && j==m-1)
            {
                continue;
            }
            else if(i==n-1)
            {
                if(a[i][j]!='X' && a[i][j+1]!='X' && dp[i][j+1].second!=0)
                {
                    dp[i][j].first+=dp[i][j+1].first+val;
                    dp[i][j].second+=(dp[i][j+1].second)%mod;
                }

            }
            else if(j==m-1)
            {
                if(a[i][j]!='X' && a[i+1][j]!='X' && dp[i+1][j].second!=0)
                {
                    dp[i][j].first+=dp[i+1][j].first+val;
                    dp[i][j].second+=(dp[i+1][j].second)%mod;
                }

            }
            else
            {
                if(a[i][j]!='X')
                {
                    int ma=0;
                    if(a[i][j+1]!='X' && dp[i][j+1].second!=0)
                    ma=max(ma,dp[i][j+1].first);
                    if(a[i+1][j+1]!='X' && dp[i+1][j+1].second!=0)
                    ma=max(ma,dp[i+1][j+1].first);
                    if(a[i+1][j]!='X' && dp[i+1][j].second!=0)
                    ma=max(ma,dp[i+1][j].first);

                    dp[i][j].first+=ma+val;

                    if(ma==dp[i][j+1].first && dp[i][j+1].second!=0)
                    dp[i][j].second+=(dp[i][j+1].second)%mod;
                    if(ma==dp[i+1][j+1].first && dp[i+1][j+1].second!=0)
                    dp[i][j].second+=(dp[i+1][j+1].second)%mod;
                    if(ma==dp[i+1][j].first && dp[i+1][j].second!=0)
                    dp[i][j].second+=(dp[i+1][j].second)%mod;
                }
            }
            
        }
    }
    return {dp[0][0].first,dp[0][0].second};
}

int main()
{
    int n;
    cin>>n;

    vector<string> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    vector<int> ans=pathswithmaxscore(a);
    cout<<ans[0]<<" "<<ans[1];
}