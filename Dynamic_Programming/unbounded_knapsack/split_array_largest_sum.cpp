#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int


//https://leetcode.com/problems/split-array-largest-sum/

vector<vector<int>> dp(1001,vector<int>(51,-1));

int top_down(vector<int>& pre,int m,int cur)
{
    if(dp[cur][m]!=-1)
    return dp[cur][m];

    int n=pre.size()-1;

    if(m==1)
    return dp[cur][m]=pre[n]-pre[cur];

    int ans=INT_MAX;

    for(int i=cur;i<=n-m;i++)
    {
        int firstsplitSum = pre[i+1]-pre[cur];

        int largestsplitSum = max(firstsplitSum,top_down(pre,m-1,i+1));

        ans=min(ans,largestsplitSum);
    }

    return dp[cur][m]=ans;
}

int bottom_up(vector<int>& pre,int m)
{
    int n=pre.size()-1;
    vector<vector<int>> dp(1001,vector<int>(51,0));

    for(int i=1;i<=m;i++)
    {
        for(int cur=0;cur<n;cur++)
        {
            if(i==1)
            {
                dp[cur][i]=pre[n]-pre[cur];
                continue;
            }

            int ans=INT_MAX;

            for(int j=cur;j<=n-m;j++)
            {
                int firstSplitsum = pre[j+1]-pre[cur];

                int largestSplitsum = max(firstSplitsum,dp[j+1][i-1]);

                ans=min(ans,largestSplitsum);

                if(firstSplitsum>=ans)
                break;
            }

            dp[cur][i]=ans;

        }

    }

    
    return dp[0][m];
}

int required(vector<int> a,int mid)
{
    int cur_sum=0;
    int split=0;

    for(auto x:a)
    {
        if(cur_sum+x<=mid)
        cur_sum+=x;
        else
        {
            split++;
            cur_sum=x;
        }

    }

    return split+1;
}

int binary_search(vector<int> a,int m)
{

    int n=a.size();

    int r=accumulate(a.begin(),a.end(),0);
    int l=*max_element(a.begin(),a.end());

    int ans=0;

    while(l<=r)
    {
        int mid = l+(r-l)/2;

        if(required(a,mid)<=m)
        {
            r=mid-1;
            ans=mid;
        } 
        else
        l=mid+1;
    }

    return ans;

}


int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    int m;
    cin>>m;

    vector<int> pre(n+1,0);

    for(int i=0;i<n;i++)
    {
        pre[i+1]=pre[i]+a[i];
    }


    cout<<top_down(pre,m,0)<<endl;
    cout<<bottom_up(pre,m)<<endl;
    cout<<binary_search(a,m);
}