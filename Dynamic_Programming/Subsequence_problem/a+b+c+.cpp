#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

int getabc(string s)
{
    int n=s.size();

    vector<vector<int>> dp(4,vector<int>(n+1,0));

    for(int i=1;i<4;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==1)
            {
                if(s[j-1]=='a')
                dp[i][j]=2*dp[i][j-1]+1;
                else
                dp[i][j]=dp[i][j-1];
            }
            else if(i==2)
            {
                if(s[j-1]=='b')
                dp[i][j]=2*dp[i][j-1]+dp[i-1][j-1];
                else
                dp[i][j]=dp[i][j-1];
            }
            else if(i==3)
            {
                if(s[j-1]=='c')
                dp[i][j]=2*dp[i][j-1]+dp[i-1][j-1];
                else
                dp[i][j]=dp[i][j-1];
            }
            
        }
    }

    return dp[3][n];
}


int main()
{
    string s;
    cin>>s;

    cout<<getabc(s);
}