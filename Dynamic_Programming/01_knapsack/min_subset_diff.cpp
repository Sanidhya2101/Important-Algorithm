#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/

int subset(vector<int> a,int k)
{
    int n=a.size();
    vector<vector<int>> v(n+1,vector<int>(k+1));

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<k+1;j++)
        {
            if(j==0)
            v[i][j]=1;
            else if(i==0)
            v[i][j]=0;
            else if(a[i-1]<=j)
            {
                v[i][j]=v[i-1][j-a[i-1]]|v[i-1][j];
            }
            else
            v[i][j]=v[i-1][j];
        }
    }
    int diff=0;
    for(int j=k/2;j>=0;j--)
    {
        if(v[n][j])
        {
            diff=abs(k-2*j);
            break;
        }
    }

    return diff;
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
    
    cout<<subset(a,sum);
    

}