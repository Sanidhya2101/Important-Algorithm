#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> t;
int n;
string p;

vector<int> merge(vector<int> a,vector<int> b)
{
    vector<int> c(26,0);
    for(int i=0;i<26;i++)
    c[i]=a[i]+b[i];
    
    return c;
}

void buildtree(int node,int start,int end)
{
    if(start==end)
    {
        t[node][p[start]-'a']=1;
        return;
    }
    
    int mid=(start+end)/2;
    buildtree(2*node,start,mid);
    buildtree(2*node+1,mid+1,end);
    
    t[node]=merge(t[2*node],t[2*node+1]);
}

int xorr(vector<int> a)
{
    int ans=0;
    for(auto x:a)
    ans^=x;
    
    return ans;
}

vector<int> query(int node,int start,int end,int left,int right)
{
    if(end<left || right<start)
    return vector<int>(26,0);
    
    if(start==end)
    return t[node];
    
    if(left<=start && end<=right)
    return t[node];
    
    int mid=(start+end)/2;
    
    vector<int> l=query(2*node,start,mid,left,right);
    vector<int> r=query(2*node+1,mid+1,end,left,right);
    
    return merge(l,r);
}

void update(int node,int start,int end,int p,int val)
{
    if(start==end)
    {
        for(int i=0;i<26;i++)
        t[node][i]=0;
        t[node][val]=1;
        return;
    }
    
    int mid=(start+end)/2;
    
    if(start<=p && p<=mid)
    update(2*node,start,mid,p,val);
    else
    update(2*node+1,mid+1,end,p,val);

    t[node]=merge(t[2*node],t[2*node+1]);
}


int main()
{
    string s;
    cin>>s;
    
    n=s.size();
    p=s;
    t.resize(4*n,vector<int>(26,0));
    
    buildtree(1,0,n-1);
    
    int q;
    cin>>q;
    
    while(q--)
    {
        int tt;
        cin>>tt;
        
        if(tt==1)
        {
            int l,r;
            cin>>l>>r;
            vector<int> tmp=query(1,0,n-1,l-1,r-1);
            int ans=0;
            for(auto x:tmp)
            ans^=x;

            cout<<ans<<" ";
        }
        else
        {
            int x,y;
            cin>>x>>y;
            update(1,0,n-1,x-1,y-1);
                

        }
    }
}