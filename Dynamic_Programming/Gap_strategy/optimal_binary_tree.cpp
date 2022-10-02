#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//https://practice.geeksforgeeks.org/problems/optimal-binary-search-tree2214/1

int optimalSearchTree(vector<int> keys,vector<int> freq)
{
    int n=keys.size();
    vector<vector<int>> dp(n,vector<int>(n,0));

    for(int g=0;g<n;g++)
    {
        for(int i=0,j=g;j<n;i++,j++)
        {
            if(g==0)
            dp[i][j]=freq[i];
            else if(g==1)
            dp[i][j]=min(freq[i]+2*freq[j],freq[j]+2*freq[i]);
            else
            {
                int fs=0;
                for(int x=i;x<=j;x++)
                fs+=freq[x];
                int mi=INT_MAX;
                for(int k=i;k<=j;k++)
                {
                    int left=(k==i)?0:dp[i][k-1];
                    int right=(k==j)?0:dp[k+1][j];
                    mi=min(left+right+fs,mi);
                }
                dp[i][j]=mi;
            }
        }
    }

    return dp[0][n-1];
}

int main()
{
    int n;
    cin>>n;

    vector<int> keys(n),freq(n);

    for(int i=0;i<n;i++)
    cin>>keys[i];

    for(int i=0;i<n;i++)
    cin>>freq[i];

    cout<<optimalSearchTree(keys,freq);
}