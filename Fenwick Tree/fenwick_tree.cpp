#include<bits/stdc++.h>
using namespace std;

class FenwickTree{
    
    vector<int> ftree;
    int n;
    public:
    FenwickTree(vector<int> a)
    {
        n=a.size();
        ftree.resize(n,0);
        vector<int> pre(n,0);

        for(int i=1;i<n;i++)
        pre[i]=pre[i-1]+a[i];

        for(int i=1;i<n;i++)
        {
            int j=i-(i&-i);
            ftree[i]=pre[i]-pre[j];
        }
    }
    
    void update(int p,int val)
    {
        while(p<n)
        {
            ftree[p]+=val;
            p+=(p&-p);
        }
    }
    
    int query(int l,int r)
    {
        return prefix(r)-prefix(l-1);
    }
    
    int prefix(int p)
    {
        int sum=0;
        while(p>0)
        {
            sum+=ftree[p];
            p-=(p&-p);
        }
        
        return sum;
    }
      
};


int main()
{
    int n;
    cin>>n;
    
    vector<int> a(n+1);
    
    for(int i=1;i<=n;i++)
    cin>>a[i];
    
    int q;
    cin>>q;
    
    FenwickTree f(a);
    
    while(q--)
    {
        char c;
        cin>>c;
        
        if(c=='q')
        {
            int l,r;
            cin>>l>>r;
            
            cout<<f.query(l,r)<<"\n";
        }
        else
        {
            int p,val;
            cin>>p>>val;
            f.update(p,val);
        }
        
    }
}
