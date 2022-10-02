#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

void floyd_warshall(vector<vector<int>> &mat)
{
    int n=mat.size();
	for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==-1 && mat[i][k]!=-1 && mat[k][j]!=-1)
                {
                    mat[i][j]=mat[i][k]+mat[k][j];
                }
                else if(mat[i][k]!=-1 && mat[k][j]!=-1 && mat[i][j]>mat[i][k]+mat[k][j])
                mat[i][j]=mat[i][k]+mat[k][j];
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;

    vector<vector<int>> mat(n,vector<int>(n,-1));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin>>mat[i][j];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<mat[i][j]<<" ";
        cout<<"\n";
    }
}