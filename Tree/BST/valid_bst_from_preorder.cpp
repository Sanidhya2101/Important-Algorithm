#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

bool using_stack(vector<int> a)
{
    stack<int> s;
    int root=INT_MIN;

    for(int i=0;i<a.size();i++)
    {
        while(!s.empty() && s.top()<a[i])
        {
            root=s.top();
            s.pop();
        }

        if(a[i]<root)
        return false;

        s.push(a[i]);
    }

    return true;

}

void using_narrowing_bound(vector<int> a,int &index,int mi,int ma)
{
    if(index>=a.size())
    return;

    if(a[index]>=mi && a[index]<=ma)
    {
        int root=a[index];
        index++;

        using_narrowing_bound(a,index,mi,root);
        using_narrowing_bound(a,index,root,ma);
    }
}


int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    cout<<using_stack(a);

    int index=0;

    using_narrowing_bound(a,index,INT_MIN,INT_MAX);

    if(index==a.size())
    cout<<0;
    else
    cout<<1;
}