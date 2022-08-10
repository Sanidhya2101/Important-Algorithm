#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/minimum-falling-path-sum-ii/

int get_min_sum_path(vector<vector<int>> a)
{
    int n=a.size();

    int min1=0;
    int min2=0;
    int min1_pos=-1;
    int min2_pos=-1;

    for(int i=0;i<n;i++)
    {
        int cur_min1=INT_MAX;
        int cur_min1_pos=-1;
        int cur_min2=INT_MAX;
        int cur_min2_pos=-1;

        for(int j=0;j<n;j++)
        {
            int val=0;
            if(j!=min1_pos)
            val=a[i][j]+min2;
            else
            val=a[i][j]+min1;

            if(cur_min1>val)
            {
                cur_min2=cur_min1;
                cur_min2_pos=cur_min1_pos;
                cur_min1=val;
                cur_min1_pos=j;
            }
            else if(cur_min2>val)
            {
                cur_min2=val;
                cur_min2_pos=j;
            }
            min1=cur_min1;
            min2=cur_min2;
            min1_pos=cur_min1_pos;
            min2_pos=cur_min2_pos;
        }

        return min1;
    }

}

int main()
{
    int n;
    cin>>n;

    vector<vector<int>> a(n,vector<int>(n));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }   

    cout<<get_min_sum_path(a);
}