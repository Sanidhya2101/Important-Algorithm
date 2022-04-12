#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//hello geek
//gehekllo or gheekllo

int main()
{
    string a,b;
    cin>>a>>b;

    int n=a.size();
    int m=b.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1));

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(i==0 || j==0)
            dp[i][j]=0;
            else if(a[i-1]==b[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    int i=n;
    int j=m;
    
    string ans;


    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1])
        {
            ans=a[i-1]+ans;
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                ans=a[i-1]+ans;
                i--;
            }
            else
            {
                ans=b[j-1]+ans;
                j--;
            }
        }
    }

    while(i>0)
    {
        ans=a[i-1]+ans;
        i--;
    }

    while(j>0)
    {
        ans=b[j-1]+ans;
        j--;
    }

    cout<<ans;
}