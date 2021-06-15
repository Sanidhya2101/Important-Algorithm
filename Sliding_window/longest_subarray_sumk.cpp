#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul long long int

// 4 1 1 1 2 3 5
//k=5

//not applicable for negative numbers


int getsizeofsumk(vector<int>& a,int k)
{
    int ans=0;

    int i=0;
    int j=0;

    int sum=0;

    while(j<a.size())
    {
        sum+=a[j];
        if(sum<k)
        {
            j++;
        }
        else if(sum==k)
        {
            ans=max(ans,j-i+1);
            j++;
        }
        else
        {
            while(sum>k)
            {
                sum-=a[i];
                i++;
            }
            if(sum==k)
            {
                ans=max(ans,j-i+1);
            }
            j++;
            
        }
    }

    return ans;
}

int main()
{
    int n,k;
    cin>>n>>k;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<getsizeofsumk(a,k);
}