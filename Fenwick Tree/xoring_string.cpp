#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> btree; 

void update(vector<int> &t,int x,int k)
{
    while(x<t.size())
    {
        t[x]+=k;
        x+=(x&(-x));
    }
}

int query(vector<int> &t,int p)
{
    int ans=0;
    while(p>0)
    {
        ans+=t[p];
        p-=(p&(-p));
    }
    return ans;
}

int main()
{
    string s;
    cin>>s;

    int n=s.size();
    
    btree.resize(26,vector<int>(n+1,0));

    for(int i=0;i<n;i++)
    update(btree[s[i]-'a'],i+1,1);

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
            int ans=0;
            for(int i=0;i<26;i++)
            ans^=query(btree[i],r)-query(btree[i],l-1);

            cout<<ans<<"\n";
        }
        else
        {
            int a,b;
            cin>>a>>b;
            update(btree[s[a-1]-'a'],a,-1);
            s[a-1]=b+'a'-1;
            update(btree[s[a-1]-'a'],a,1);
        }

    }

}