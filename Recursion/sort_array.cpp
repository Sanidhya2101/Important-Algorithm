#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int


void insert(vector<int> &v,int temp)
{
    if(v.size()==0 || v[v.size()-1]<=temp)
    {
        v.push_back(temp);

        return;
    }

    int val=v[v.size()-1];
    v.pop_back();
    insert(v,temp);

    v.push_back(val);

}

void sort_recursion(vector<int> &v)
{
    if(v.size()==1)
    return;

    int temp=v[v.size()-1];

    v.pop_back();

    sort_recursion(v);

    insert(v,temp);

}


int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    sort_recursion(a);

    for(auto x:a)
    cout<<x<<" ";
}