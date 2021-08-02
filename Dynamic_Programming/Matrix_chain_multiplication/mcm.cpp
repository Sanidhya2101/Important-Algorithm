#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//find A1A2A3A4 min cost

//40 20 30 10 30 dimension of array
//n-1 matrix will be there
//A1-40x20
//A2-20x30
//A3-30x10
//A4-10x30

//10 20 30 40 30
//30000

//10 20 30
//6000

vector<vector<int>> dp(1001,vector<int>(1001,-1));

int mcm_recursive(vector<int>&v,int i,int j)
{
    if(i>=j)
    return 0;



    int mi=INT_MAX;

    for(int k=i;k<j;k++)
    {
        mi = min(mi,mcm_recursive(v,i,k)+mcm_recursive(v,k+1,j)+v[i-1]*v[k]*v[j]);
    }

    return mi;

}

int mcm_memoization(vector<int>&v,int i,int j)
{
    
    if(i>=j)
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];


    int mi=INT_MAX;

    for(int k=i;k<j;k++)
    {
        mi = min(mi,mcm_recursive(v,i,k)+mcm_recursive(v,k+1,j)+v[i-1]*v[k]*v[j]);
    }

    return dp[i][j]=mi;
}

int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];


    cout<<mcm_recursive(a,1,n-1)<<endl;
    cout<<mcm_memoization(a,1,n-1);


}