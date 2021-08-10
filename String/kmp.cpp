#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

vector<int> getlps(string b)
{
    int m=b.size();

    vector<int> lps(m,0);
    int len=0;
    int i=1;

    while(i<m)
    {
        if(b[i]==b[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len==0)
            {
                lps[i]=0;
                i++;
            }
            else
            len=lps[len-1];
        }
    }

    return lps;
}

int main()
{
    string a,b;
    cin>>a>>b;

    vector<int> lps=getlps(b);

    int i=0,j=0;

    while(i<a.size())
    {
        if(a[i]==b[j])
        {
            i++;
            j++;
        }
        if(j==b.size())
        {
            cout<<i-b.size()<<" ";
            j=lps[j-1];
        }
        else
        {
            if(i<a.size() && a[i]!=b[j])
            {
                if(j==0)
                i++;
                else
                j=lps[j-1];
            }
        }
    }
}