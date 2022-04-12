#include<bits/stdc++.h>
using namespace std;


//abcdgh
//abedfhr
//abdh-4

//axyt
//ayzx

#define ll long long int
#define ul unsigned long int


    vector<vector<int>> lcs(1001,vector<int>(1001,-1));


int getrecursive(string a,string b)
{
    if(a.size()==0 || b.size()==0)
    return 0;

    
    char a1=a.back();
    char b1=b.back();
    
    a.pop_back();
    b.pop_back();

    if(a1==b1)
    {
        return getrecursive(a,b)+1;
    }


    return max(getrecursive(a+a1,b),getrecursive(a,b+b1));
}

int top_down(string a,string b)
{
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
    return dp[n][m];
}


int memoization(string a,string b,int n,int m)
{
    if(n==0 || m==0)
    return 0;

    if(lcs[n][m]!=-1)
    return lcs[n][m];

    if(a[n-1]==b[m-1])
    {
        return lcs[n][m]=memoization(a,b,n-1,m-1)+1;
    }
    else
    {
        return lcs[n][m]=max(memoization(a,b,n-1,m),memoization(a,b,n,m-1));
    }
}


string getsubsequence(string a,string b)
{
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
            dp[i][j]=dp[i-1][j-1]+1;
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    string ans;
    int i=n;
    int j=m;

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
            i--;
            else
            j--;
        }
    }

    return ans;
}



int main()
{
    string a,b;
    cin>>a>>b;


    
    cout<<getrecursive(a,b)<<endl;
    cout<<memoization(a,b,a.size(),b.size())<<endl;
    cout<<top_down(a,b)<<endl;

    cout<<getsubsequence(a,b);
}