#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

int getfloor(vector<int>& a,int k)
{
    int start=0;
    int end=a.size()-1;

    int res=0;

    while(start<=end)
    {
        int mid=start+(end-start)/2;

        if(a[mid]==k)
        return a[mid];

        if(a[mid]>k)
        end=mid-1;

        else
        {
            start=mid+1;
            res=a[mid];
        }
    }

    return res;
}

int getceil(vector<int>& a,int k)
{
    
    int start=0;
    int end=a.size()-1;

    int res=0;

    while(start<=end)
    {
        int mid=start+(end-start)/2;

        if(a[mid]==k)
        return a[mid];

        if(a[mid]>k)
        {
            end=mid-1;
            res=a[mid];
        }

        else
        {
            start=mid+1;
        }
    }

    return res;   
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

    int k;
    cin>>k;
    

    cout<<min(getceil(a,k)-k,k-getfloor(a,k));
}