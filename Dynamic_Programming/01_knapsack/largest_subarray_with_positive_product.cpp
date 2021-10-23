#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

int maxlen(vector<int> a)
{
    int n=a.size();

    int i=0;
    int ans=0;

    while(i<n)
    {
        int s=i;

        while(s<n && a[s]==0)
        s++;

        int e=s;

        int sn=-1,en=-1;

        int c=0;

        while(e<n && a[e]!=0)
        {
            if(a[e]<0)
            {
                if(sn==-1)
                sn=e;
                c++;
                en=e;
            }
            e++;
        }

        if(c%2==0)
        ans=max(ans,e-s);
        else
        {
            if(sn!=-1)
            ans=max(ans,e-sn-1);
            if(en!=-1)
            ans=max(ans,en-s);
        }
        i=e+1;
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    cout<<maxlen(a);
}