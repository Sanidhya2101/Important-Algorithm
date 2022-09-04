#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
    vector<long> sgt;
    long m;

    public:
    SegmentTree(long n,vector<long> a)
    {
        sgt.resize(2*n);
        for(long i=0;i<n;i++)
        sgt[i+n]=a[i];
        m=n;
        for(long i=n-1;i>0;i--)
        sgt[i]=0;
    }

    void range_update(long l,long h,long val)
    {
        l+=m;
        h+=m+1;

        while(l<h)
        {
            if(l&1)
            sgt[l++]+=val;
            if(h&1)
            sgt[--h]+=val;

            l>>=1;
            h>>=1;
        }
    }

    long getelement(long p)
    {
        p+=m;
        long ans=0;
        while(p>0)
        {
            ans+=sgt[p];
            p>>=1;
        }
        return ans;
    }
};

int main()
{
    long n;
    cin>>n;

    vector<long> a(n);

    for(long i=0;i<n;i++)
    cin>>a[i];

    long q;
    cin>>q;

    SegmentTree s(n,a);

    while(q--)
    {
        long t;
        cin>>t;

        if(t)
        {
            long l,h,val;
            cin>>l>>h>>val;
            s.range_update(l,h,val);
        }
        else
        {
            long p;
            cin>>p;
            cout<<s.getelement(p)<<"\n";   
        }
    }    
}