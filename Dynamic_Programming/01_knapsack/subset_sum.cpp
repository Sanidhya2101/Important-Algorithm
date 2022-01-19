#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//2 3 7 8 10
//11 
//Yes


int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    int k;
    cin>>k;

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
                v[i][j]=(v[i-1][j-a[i-1]]|v[i-1][j]);
            }
            else
            v[i][j]=v[i-1][j];
        }
    }

    cout<<v[n][k];
    

}
