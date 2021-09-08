#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

struct node{

    node* next[2];

    node()
    {
        next[0]=NULL;
        next[1]=NULL;
    }

};

void insert(int n,node* root)
{
    node* tmp=root;

    for(int i=31;i>=0;i--)
    {
        int bit=(n>>i)&1;

        if(tmp->next[bit]==NULL)
        tmp->next[bit]=new node();

        tmp=tmp->next[bit];
    }
}

int getmaxxor(vector<int> b,node* root)
{
    node* tmp;
    int ans=0;

    for(auto x:b)
    {
        tmp=root;
        int curr=0;
        for(int j=31;j>=0;j--)
        {
            int bit=(x>>j)&1;
            bit=1-bit;

            if(tmp->next[bit]!=NULL)
            {
                curr=curr<<1;
                curr=curr|1;
                tmp=tmp->next[bit];
            }
            else
            {
                curr=curr<<1;
                curr=curr|1;
                tmp=tmp->next[bit?0:1];
            }
        }

        ans=max(ans,curr);
    }

    return ans;
}


int main()
{
    int n,m;
    cin>>n>>m;

    vector<int> a(n),b(m);

    for(int i=0;i<n;i++)
    cin>>a[i];

    for(int i=0;i<m;i++)
    cin>>b[i];

    node* root=new node();

    cout<<getmaxxor(b,root);

}