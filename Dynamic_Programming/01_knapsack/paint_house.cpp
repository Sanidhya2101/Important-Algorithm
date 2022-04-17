#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

/*4 3
1 5 7
5 8 4
3 2 9
1 2 4*/

int minpaint(vector<vector<int>> a)
{
    int n=a.size();
    int k=a[0].size();

    vector<vector<int>> dp(n,vector<int>(k,0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(i==0)
            dp[i][j]=a[i][j];
            else
            {
                int mi=INT_MAX;
                for(int m=0;m<k;m++)
                {
                    if(m!=j)
                    mi=min(mi,dp[i-1][m]);
                }
                dp[i][j]=mi+a[i][j];
            }
        }
    }

    int ans=INT_MAX;

    for(int j=0;j<k;j++)
    {
        ans=min(ans,dp[n-1][j]);
    }

    return ans;
}

int minpaintoptimize(vector<vector<int>> a)
{
    int n=a.size();
    int k=a[0].size();

    vector<vector<int>> dp(n,vector<int>(k,0));

    int mi = INT_MAX;
    int smi = INT_MAX;

    for(int j=0;j<k;j++)
    {
        dp[0][j]=a[0][j];

        if(a[0][j] <= mi)
        {
            smi=mi;
            mi=a[0][j];
        }
        else if(a[0][j]<=smi)
        {
            smi=a[0][j];
        }
    }

    for(int i=1;i<dp.size();i++)
    {
        int mi_new=INT_MAX;
        int smi_new=INT_MAX;

        for(int j=0;j<dp[0].size();j++)
        {
            if(mi==dp[i-1][j])
            dp[i][j]=smi+a[i][j];
            else
            dp[i][j]=mi+a[i][j];

            if(mi_new>=dp[i][j])
            {
                smi_new=mi_new;
                mi_new=dp[i][j];
            }
            else if(smi_new>=dp[i][j])
            smi_new=dp[i][j];

        }

        mi=mi_new;
        smi=smi_new;
    } 


    return mi;
}


int main()
{
    int n,k;
    cin>>n>>k;

    vector<vector<int>> a(n,vector<int>(k));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        cin>>a[i][j];
    }

    cout<<minpaint(a)<<"\n";
    cout<<minpaintoptimize(a);

}