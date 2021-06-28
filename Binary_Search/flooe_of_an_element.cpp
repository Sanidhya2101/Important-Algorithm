#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

int getfloor(vector<int>& a,int start,int end,int k)
{
    
    if(start>end || k<a[start])
    return -1;

    if(k>=a[end])
    return a[end];

    int mid=start+(end-start)/2;

    //check if k lies between mid-1 and mid
    if(mid>0 && a[mid-1]<=k && a[mid]>k)
    return a[mid-1];

    if(a[mid]>k)
    return getfloor(a,start,mid-1,k);

    return getfloor(a,mid+1,end,k);


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

    cout<<getfloor(a,0,a.size()-1,k);
}