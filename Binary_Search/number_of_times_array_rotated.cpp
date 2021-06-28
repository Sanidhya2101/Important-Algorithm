#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//11 12 14 15 2 4 6 8 10
//clockwise rotation answer 5


int getrotation(vector<int>& a,int start,int end)
{
    //for array not rotated
    if(end<start)
    return 0;

    //if there is one element
    if(end==start)
    return start;

    int mid=start+(end-start)/2;

    if(mid<end && a[mid+1]<a[mid])
    return mid+1;

    if(mid>start && a[mid-1]>a[mid])
    return mid;

    if(a[end]>a[mid])
    return getrotation(a,start,mid-1);

    return getrotation(a,mid+1,end);
}

int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    cout<<(a.size()-getrotation(a,0,a.size()-1))%a.size();
}