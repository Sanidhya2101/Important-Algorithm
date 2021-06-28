#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

int getoccur(vector<int>& a,int start,int end,int k,int s)
{
    int res=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(a[mid]==k)
        {
            res=mid;
            if(s)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        else if(a[mid]>k)
        end=mid-1;
        else
        start=mid+1;
    }

    return res;
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


    cout<<getoccur(a,0,n-1,k,0)<<" ";
    cout<<getoccur(a,0,n-1,k,1);
}