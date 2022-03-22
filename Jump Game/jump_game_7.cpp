#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

bool canReach(string s,int a,int b)
{
    int n=s.size();
    int j=0;

    for(int i=0;i<n;i++)
    {
        if(s[i]=='o' || i==0)
        {
            for(j=max(j,i+a);j<min(n,i+b+1);j++)
            {
                if(s[j]=='0')
                s[j]='o';
            }

            if(j>n)
            break;
        }
    }

    return s[n-1]=='o';
}


int main()
{
    string s;
    cin>>s;

    int a,b;
    cin>>a>>b;

    cout<<canReach(s,a,b);
}