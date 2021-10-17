#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//[1,100,1,1,1,100,1,1,100,1]  6
//Once you pay the cost, you can either climb one or two steps.
//https://leetcode.com/problems/min-cost-climbing-stairs/


vector<int> dp(10001,0);

int getans(vector<int> a)
{
    int first=a[0];
    int second=a[1];

    for(int i=2;i<a.size();i++)
    {
        int cur=a[i]+min(first,second);

        first=second;
        second=cur;
    }

    return min(first,second);
}

int dpans(vector<int> a,int n)
{
    if(n<=0)
    return 0;

    if(dp[n]!=0)
    return dp[n];

    return dp[n]=min(a[n]+dpans(a,n-1),a[n-1]+dpans(a,n-2));
}


int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<getans(a)<<"\n";
    cout<<dpans(a,n-1);
}