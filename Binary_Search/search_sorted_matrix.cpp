#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//10 20 30 40
//15 25 35 45
//27 29 37 48
//32 33 39 50

vector<int> getk(vector<vector<int>>& a,int k)
{
    int n=a.size();
    int m=a[0].size();

    int i=0;
    int j=m-1;

    while(i<n && j>=0)
    {
        if(a[i][j]==k)
        {
            return {i+1,j+1};
        }

        if(a[i][j]<k)
        i++;

        else
        j--;
    }

    return {-1};
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> a(n,vector<int>(m));

    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    cin>>a[i][j];

    int k;
    cin>>k;

    if(getk(a,k)[0]==-1)
    cout<<-1;

    else
    {
        for(auto x:getk(a,k))
        cout<<x<<" ";
    }
}