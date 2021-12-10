#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int
#define mod 1000000007
//https://leetcode.com/problems/domino-and-tromino-tiling/solution/

vector<vector<int>> dp(1000+1,vector<int>(4,-1));

int makestate(bool t1,bool t2)
{
    if(!t1 && !t2)
    return 0;

    if(t1 && !t2)
    return 1;

    if(!t1 && t2)
    return 2;

    return 3; 
}


int dp_sol(int i,int n,bool t1,bool t2)
{
    if(i==n)
    return 1;

    int state=makestate(t1,t2);

    if(dp[i][state]!=-1)
    return dp[i][state];

    int cnt=0;

    bool t3=(i+1<n);
    bool t4=(i+1<n);

    if(t1 && t2 && t3)
    cnt+=dp_sol(i+1,n,false,true);

    if(t1 && t2 && t4)
    cnt+=dp_sol(i+1,n,true,false);

    if(t1 && !t2 && t3 && t4)
    cnt+=dp_sol(i+1,n,false,false);

    if(!t1 && t2 && t3 && t4)
    cnt+=dp_sol(i+1,n,false,false);

    if(t1 && t2)
    cnt+=dp_sol(i+1,n,true,true);

    if(t1 && t2 && t3 && t4)
    cnt+=dp_sol(i+1,n,false,false);

    if(t1 && !t2 && t3)
    cnt+=dp_sol(i+1,n,false,true);

    if(!t1 && t2 && t4)
    cnt+=dp_sol(i+1,n,true,false);

    if(!t1 && !t2)
    cnt+=dp_sol(i+1,n,true,true);

    return dp[i][state]=cnt%mod; 

}

int dp_sol_alt(int n)
{
    vector<int> dp(n+1,0);

    if(n==1)
    return 1;
    if(n==2)
    return 2;
    if(n==3)
    return 5;

    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    dp[3]=5;

    for(int i=4;i<n+1;i++)
    dp[i]=2*dp[i-1]+dp[i-3];

    return dp[n];
}

int main()
{
    int n;
    cin>>n;

    cout<<dp_sol(0,n,true,true)<<"\n";

    cout<<dp_sol_alt(n);

}