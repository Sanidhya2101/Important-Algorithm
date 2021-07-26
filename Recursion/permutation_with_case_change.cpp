#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int


void getpermutation(string s,string out)
{
    if(s.empty())
    {
        cout<<out<<"\n";
        return;
    }

    char c=s[0];

    s.erase(s.begin()+0);

    getpermutation(s,out+c);

    if(c>='a' && c<='z')
    c-='a'-'A';
    else
    c+='a'-'A';

    getpermutation(s,out+c);
}

int main()
{
    string s;
    cin>>s;

    string ans;
    getpermutation(s,ans);
}