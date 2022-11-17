#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
    
    vector<int> sgt;
    vector<int> lazy;
    vector<int> a;
    
    public:
    SegmentTree(vector<int> arr)
    {
        a=arr;
        int n=a.size();
        sgt.resize(4*n,0);
        lazy.resize(4*n,0);
        
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
        
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        
        sgt[node]=sgt[2*node]+sgt[2*node+1];
        //lazy[node]=0;
    }
     
    void propogate(int node,int start,int end)
    {
        if(start==end)
        {
            sgt[node]+=lazy[node];
            lazy[node]=0;
            return;
        }
        
        sgt[node]+=lazy[node]*(end-start+1);
        lazy[2*node]+=lazy[node];
        lazy[2*node+1]+=lazy[node];
        lazy[node]=0;
    }
     
    int query(int node,int start,int end,int l,int r)
    {
        propogate(node,start,end);
        
        if(end<l || r<start)
        return 0;
        
        
        if(start==end)
        return sgt[node];
        
        if(l<=start && end<=r)
        return sgt[node];
        
        int mid=(start+end)/2;
        
        int left=query(2*node,start,mid,l,r);
        int right=query(2*node+1,mid+1,end,l,r);
        
        return left+right;
    }
    
    
    void update_range(int node,int start,int end,int l,int r,int val)
    {
        propogate(node,start,end);
        if(end<l || r<start)
        return;
        
        if(start==end)
        {
            sgt[node]+=val;
            return;
        }
        else if(l<=start && end<=r)
        {
            lazy[node]+=val;
            propogate(node,start,end);
            return;
        }
        
        int mid=(start+end)/2;
        
        update_range(2*node,start,mid,l,r,val);
        update_range(2*node+1,mid+1,end,l,r,val);
        
        sgt[node]=sgt[2*node]+sgt[2*node+1];
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
    
    SegmentTree s(a);
    
    while(q--)
    {
        int t;
        cin>>t;
        
        if(t)
        {
            int l,r,val;
            cin>>l>>r>>val;
            s.update_range(1,0,n-1,l,r,val);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            cout<<s.query(1,0,n-1,l,r)<<"\n";
        }
        
    }
}