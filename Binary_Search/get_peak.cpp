#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

int getpeak(vector<int>& a)
{
    int start=0;
    int end=a.size()-1;

    if(a[start]>a[start+1])
    return a[start];

    if(a[end]>a[end-1])
    return a[end];

    while(start<=end)
    {
        int mid=start+(end-start)/2;

        if(a[mid]>a[mid-1] && a[mid+1]<a[mid])
        return a[mid];

        else if(a[mid-1]>a[mid])
        end=mid-1;

        else if(a[mid+1]>a[mid])
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

    cout<<getpeak(a);

}