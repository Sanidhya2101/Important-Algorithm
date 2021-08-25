#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

vector<int> getans(int n,int k)
{
    int cnt=0;
    int low=0;
    int high=n;

    while(low<=high)
    {
        int mid=low+(high-low)/2;

        int sum=mid*(mid+1)/2;

        if(sum<=n)
        {
            cnt=mid/k;

            low=mid+1;
        }
        else
        high=mid-1;
    }

    int last=cnt*k;

    n-=(last)*(last+1)/2;

    int i=0;

    int term=cnt*k+1;

    vector<int> a(k,0);

    while(n)
    {
        if(term<=n)
        {
            a[i]=term;
            
            i++;
            n-=term;
            term++;

        }
        else
        {
            a[i]+=n;
            n=0;
        }
    }

    for(int i=0;i<k;i++)
    {
        a[i]+=(cnt*(i+1))+(k*(cnt)*(cnt-1)/2);
    }

    return a;
}


int main()
{
    int n,k;
    cin>>n>>k;

    for(auto x:getans(n,k))
    cout<<x<<" ";
}