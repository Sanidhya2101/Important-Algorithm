#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

bool isvalid(vector<int>& a,int k,int mid)
{
    int student=1;
    int sum=0;

    for(auto x:a)
    {
        sum+=x;
        if(sum>mid)
        {
            student++;
            sum=x;
        }

        if(student>k)
        return false;
    }

    return true;
}


int getminpage(vector<int>& a,int k)
{
    if(a.size()<k)
    return -1;

    int start=0;
    int end=accumulate(a.begin(),a.end(),0);

    int ans=-1;

    while(start<=end)
    {
        int mid=start+(end-start)/2;

        if(isvalid(a,k,mid))
        {
            ans=mid;
            end=mid-1;
        }
        else
        start=mid+1;
    }
}

int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    int k;
    cin>>k;

    cout<<getminpage(a,k);
}