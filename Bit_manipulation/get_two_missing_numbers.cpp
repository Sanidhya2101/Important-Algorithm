#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

pair<int,int> getans(vector<int> a,int n)
{
    int c=0;
    for(int i=0;i<n-2;i++)
    c^=a[i];

    for(int i=1;i<=n;i++)
    c^=i;

    int set_bit = c & ~(c-1);

    int x=0;
    int y=0;

    for(int i=0;i<n-2;i++)
    {
        if(set_bit&a[i])
        x^=a[i];
        else
        y^=a[i];
    }

    for(int i=1;i<=n;i++)
    {
        if(i&set_bit)
        x^=i;
        else
        y^=i;
    }

    return {x,y};


}

int main()
{
    int n;
    cin>>n;

    vector<int> a(n-2);

    for(int i=0;i<n-2;i++)
    {
        cin>>a[i];
    }

    pair<int,int> p=getans(a,n);

    cout<<p.first<<" "<<p.second;
}