#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int


void mergearray(vector<int> &a,vector<int> &b)
{
    int n=a.size();
    int m=b.size();

    int ma=0;

    for(auto x:a)
    ma=max(ma,x);

    for(auto x:b)
    ma=max(ma,x);

    ma++;

    int i=0,j=0,k=0;

    while(i<n && j<m && k<n+m)
    {
        int e1=a[i]%ma;
        int e2=b[j]%ma;

        if(e1<=e2)
        {
            if(k<n)
            {
                a[k]+=(e1*ma);
            }
            else
            b[k-n]+=e1*ma;

            i++;
            k++;
        }
        else
        {
            if(k<n)
            a[k]+=e2*ma;
            else
            b[k-n]+=e2*ma;

            j++;
            k++;
        }
    }

    while(i<n)
    {
        if(k<n)
        a[k]+=(a[i]%ma)*ma;
        else
        b[k-n]+=(a[i]%ma)*ma;

        i++;
        k++;
    }

    while(j<m)
    {
        if(k<n)
        a[k]+=(b[j]%ma)*ma;
        else
        b[k-n]+=(b[j]%ma)*ma;

        j++;
        k++;
    }

    for(int i=0;i<n;i++)
    a[i]=a[i]/ma;

    for(int i=0;i<m;i++)
    b[i]=b[i]/ma;

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

    mergearray(a,b);

    for(auto x:a)
    cout<<x<<" ";

    for(auto x:b)
    cout<<x<<" ";
}