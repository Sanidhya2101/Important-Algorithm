#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//nitin


//ababbbabbababa
//a|babbbab|b|ababa

vector<vector<int>> dp(1001,vector<int>(1001,-1));

bool ispalindrome(string s,int i,int j)
{
    while(i<j)
    {
        if(s[i]!=s[j])
        return false;

        i++;
        j--;
    }

    return true;
}


int getpartition(string s,int i,int j)
{
    if(i>=j || ispalindrome(s,i,j))
    return 0;

    int mi=INT_MAX;

    for(int k=i;k<j;k++)
    {
        mi=min(mi,getpartition(s,i,k)+getpartition(s,k+1,j)+1);
    }

    return mi;
}


int getpartition_memoization(string s,int i,int j)
{
    if(i>=j || ispalindrome(s,i,j))
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];

    int ans=INT_MAX;

    for(int k=i;k<j;k++)
    {
        ans=min(ans,getpartition(s,i,k)+getpartition(s,k+1,j)+1);
    }

    return dp[i][j]=ans;
}

//top-down approach
int minCut(string s) {
        int n=s.size();
        vector<vector<bool>> ispal(n,vector<bool>(n,false));
        
        for(int g=0;g<n;g++)
        {
            for(int i=0,j=g;j<n;i++,j++)
            {
                if(g==0)
                    ispal[i][j]=true;
                else if(g==1)
                    ispal[i][j]=(s[i]==s[j]);
                else
                    ispal[i][j]=((s[i]==s[j])&&ispal[i+1][j-1]);
            }
        }
        vector<int> dp(n,0);
    
        for(int j=1;j<n;j++)
        {
            if(ispal[0][j])
            {
                dp[j]=0;
                continue;
            }
            int mi=INT_MAX;
            for(int i=j;i>=1;i--)
            {
                if(ispal[i][j])
                mi=min(mi,dp[i-1]+1);
            }
            dp[j]=mi;
        }
        return dp[n-1];
    }


int main()
{
    string s;
    cin>>s;

    cout<<getpartition(s,0,s.size()-1)<<endl;
    cout<<getpartition_memoization(s,0,s.size()-1);
}