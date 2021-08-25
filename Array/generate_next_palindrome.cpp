#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

bool isallnine(string s)
{
    for(int i=0;i<s.size();i++)
    if(s[i]!='9')
    return 0;

    return 1;
}

void generatepalindrome(string &s)
{
    int m=s.size()/2;

    int i=m-1;

    int j=(s.size()%2)?m+1:m;

    while(i>=0 && s[i]==s[j])
    {
        i--;
        j++;
    }

    bool f=false;

    if(i<0 || s[i]-'0'<s[j]-'0')
    f=true;

    while(i>=0)
    {
        s[j++]=s[i--];
    }

   // cout<<f<<" ";

    if(f)
    {
        int c=1;
        i=m-1;

        if(s.size()%2==1)
        {
            int a=s[m]-'0'+c;
            c=a/10;
            a%=10;
            s[m]=a+'0';
            j=m+1;
        }
        else
        j=m;


        while(i>=0)
        {
            int a=s[i]-'0'+c;
            c=a/10;
            a%=10;
            s[i]=a+'0';

            s[j++]=s[i--];   
        }
    }
}

int main()
{
    int n;
    cin>>n;

    string s=to_string(n);

    if(isallnine(s))
    {
        cout<<1;
        for(int i=0;i<s.size()-1;i++)
        cout<<0;
        cout<<1;
        return 0;
    }
    
    generatepalindrome(s);

    cout<<s;
}