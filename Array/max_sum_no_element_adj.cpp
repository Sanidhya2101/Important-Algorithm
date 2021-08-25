#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

int getmaxsum(vector<int> a)
{
    int inc=a[0];
    int exc=0;
    int new_exc;

    for(int i=1;i<a.size();i++)
    {
        new_exc=max(inc,exc);

        inc=exc+a[i];
        exc=new_exc;
    }

    return max(inc,exc);
}

int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    cout<<getmaxsum(a);
}