#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

// 1 5 11 5

int subsetsum(vector<int> a,int sum)
{
    int n=a.size();

    vector<vector<int>> v(n+1,vector<int>(sum+1));

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(j==0)
            v[i][j]=1;
            else if(i==0)
            v[i][j]=0;
            else if(a[i-1]<=j)
            v[i][j]=v[i-1][j-a[i-1]]|v[i-1][j];
            else
            v[i][j]=v[i-1][j];

        }
    }

    return v[n][sum];
}

int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    int sum=0;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }

    if(sum&1)
    {
        cout<<0;
    }
    else
    cout<<subsetsum(a,sum/2); 
}