#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

void DFS_recursion(int s,vector<int> a[],vector<int> &v)
{
    cout<<s<<" ";
    v[s]=1;

    for(auto x:a[s])
    {
        if(!v[x])
        {
            DFS_recursion(x,a,v);
        }
    }
}

void DFS_iterative(int s,vector<int> a[],vector<int> &v)
{
    stack<int> st;
    st.push(s);

    while(!st.empty())
    {
        s=st.top();
        st.pop();
        if(!v[s])
        {
            cout<<s<<" ";
            v[s]=1;
        }

        for(auto x:a[s])
        {
            if(!v[x])
            st.push(x);
        }
    }
    
}


int main()
{
    int n;
    cin>>n;
    vector<int> a[n+1];
    vector<int> v(n+1,0);

    int p=n;
    while(p--)
    {
        int x;
        cin>>x;
        while(1)
        {
            int y;
            cin>>y;
            if(y==-1)
            break;
            a[x].push_back(y);
            a[y].push_back(x);
        }
    }

    DFS_recursion(1,a,v);
    for(auto &x:v)
    x=0;
    cout<<"\n";
   DFS_iterative(1,a,v);
}