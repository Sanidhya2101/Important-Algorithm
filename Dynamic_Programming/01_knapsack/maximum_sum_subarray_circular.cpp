#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//https://leetcode.com/problems/maximum-sum-circular-subarray/

int kadane(vector<int> a)  //O(n^2)
{
    
    int n=a.size();

    int s=0;
    int e=n-1;


    int max_sum=INT_MIN;

    while(s<n)
    {
        int cur_sum=0;
        int i=s;
        do
        {
            cur_sum+=a[i];
            max_sum=max({max_sum,cur_sum,a[i]});

            if(cur_sum<a[i])
            cur_sum=a[i];

            i=(i+1)%n;
        }while(i!=(e+1)%n);

        e=(e+1)%n;
        s++;
    }

    return max_sum;
}


int optimise(vector<int> a)
{
    int n=a.size();

    int sum=0;

    int max_sum=INT_MIN;
    int cur_max=0;

    int min_sum=INT_MAX;
    int cur_min=0;

    for(int i=0;i<n;i++)
    {
        cur_max+=a[i];
        max_sum=max({max_sum,a[i],cur_max});
        if(cur_max<a[i])
        cur_max=a[i];

        cur_min+=a[i];
        min_sum=min({min_sum,a[i],cur_min});
        if(cur_min>a[i])
        cur_min=a[i];

        sum+=a[i];
    }

    if(min_sum==sum)
    return max_sum;

    return max(sum-min_sum,max_sum);
}



int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    } 

    cout<<kadane(a)<<"\n";
}