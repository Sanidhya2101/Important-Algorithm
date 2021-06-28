#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

int getmax(vector<int>& a,int start,int end)
{
    if(start==end)
    return a[end];

    int mid=start+(end-start)/2;

    if(a[mid]>a[mid+1] && a[mid]>a[mid-1])
    return a[mid];

    if(a[mid]>a[mid+1])
    return getmax(a,start,mid-1);

    return getmax(a,mid+1,end);
}

int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    cout<<getmax(a,0,n-1);
}