#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//11 12 14 15 2 4 6 8 10

int bs(vector<int>& a,int start,int end,int k)
{
    if(start>end)
    return -1;

    int mid=start+(end-start)/2;

    if(a[mid]==k)
    return mid;

    if(a[mid]>k)
    return bs(a,start,mid-1,k);

    return bs(a,mid+1,end,k);
}


//this function will return position of 15
int getpivot(vector<int>& a,int low,int high)
{
    if(low>high)
    return -1;

    if(low==high)
    return low;

    int mid=low+(high-low)/2;

    if(mid<high && a[mid]>a[mid+1])
    return mid;

    if(mid>low && a[mid]<a[mid-1])
    return mid-1;

    if(a[low]>=a[mid])
    return getpivot(a,low,mid-1);

    return getpivot(a,mid+1,high);

}

int getk(vector<int>& a,int start,int end,int k)
{
    int pivot = getpivot(a,start,end);

    if(pivot==-1)
    return bs(a,start,end,k);

    if(a[pivot]==k)
    return pivot;

    if(a[0]>k)
    return bs(a,pivot+1,end,k);

    return bs(a,0,pivot-1,k);
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

    cout<<getk(a,0,n-1,k);
}