#include<bits/stdc++.h>
using namespace std;

//top down approach
class SegmentTree{
    vector<int> sgt;
    vector<int> a;

    public:

    SegmentTree(int n,vector<int> &arr)
    {
        a=arr;
        sgt.resize(4*n);
        build(1,0,n-1);
    }

    void build(int node,int start,int end)
    {
        if(start==end)
        {
            sgt[node]=a[start];
            return;
        }
        int mid=(start+end)/2;
        int left=2*node;
        int right=2*node+1;
        build(left,start,mid);
        build(right,mid+1,end);

        sgt[node]=max(sgt[left],sgt[right]);
    }

    int query(int node,int start,int end,int l,int h)
    {
        
        if(end<l || h<start)
        return INT_MIN;
        if(start==end)
        return sgt[node];
        if(l<=start && end<=h)
        return sgt[node];

        int mid=(start+end)/2;

        int left=query(2*node,start,mid,l,h);
        int right=query(2*node+1,mid+1,end,l,h);

        return max(left,right);
    }

    int getmax(int l,int h)
    {
        return query(1,0,a.size()-1,l,h);
    }
};


class EfficientSegmentTree{
    vector<int> sgt;
    int n;

//bottom up approach
    public:
    EfficientSegmentTree(int n,vector<int> a)
    {
        sgt.resize(2*n);
        for(int i=0;i<n;i++)
        sgt[i+n]=a[i];
        n=n;
        for(int i=n-1;i>0;i--)
        sgt[i]=max(sgt[i<<1],sgt[i<<1|1]);
    }

    int getmax(int l,int r)
    {
        int ans=INT_MIN;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1)
        {
            if(l&1)
            ans=max(ans,sgt[l++]);
            if(r&1)
            ans=max(ans,sgt[--r]);
        }

        return ans;
    }

    void update(int p,int val)
    {
        p+=n;
        sgt[p]=val;
        while(p>1)
        {
            sgt[p>>1]=max(sgt[p],sgt[p^1]);
            p>>=1;
        }
    }
};

int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    int q;
    cin>>q;

    EfficientSegmentTree s(n,a);

    while(q--)
    {
        int t,l,h;
        cin>>t>>l>>h;

        if(t)
        cout<<s.getmax(l,h)<<"";
        else
        s.update(l,h);
    }    
}