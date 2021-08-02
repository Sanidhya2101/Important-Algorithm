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


int main()
{
    string s;
    cin>>s;

    cout<<getpartition(s,0,s.size()-1)<<endl;
    cout<<getpartition_memoization(s,0,s.size()-1);
}