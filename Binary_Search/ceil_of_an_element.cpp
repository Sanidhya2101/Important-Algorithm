#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

int getceil(vector<int>& a,int start,int end,int k)
{
    if(start>end)
    return -1;

    if(a[end]<k)
    return -1;

    if(a[start]>=k)
    return a[start];

    int mid=start+(end-start)/2;

    if(a[mid]==k)
    return a[mid];

    if(a[mid]<k)
    {
        /* If k is greater than a[mid],
       then either a[mid + 1] is ceiling of k
       or ceiling lies in a[mid+1...high] */
        if(mid<end && a[mid+1]>=k)
        return a[mid+1];

        return getceil(a,mid+1,end,k);
    }

    if(a[mid]>=k)
    {
        /*If k is smaller than a[mid],
       then either arr[mid] is ceiling of k
       or ceiling lies in a[low...mid-1]*/ 
        if(mid>start && a[mid-1]<k)
        return a[mid];

        return getceil(a,start,mid-1,k);
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

    cout<<getceil(a,0,a.size()-1,k);
}