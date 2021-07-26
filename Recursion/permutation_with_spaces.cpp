#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

void getpermutation(string s,string ans)
{
    if(s.size()==0)
    {
        cout<<ans<<"\n";
        return;
    }

    char tmp=s[0];
    s.erase(s.begin()+0);

    getpermutation(s,ans+tmp);

    getpermutation(s,ans+" "+tmp);
}

int main()
{
    string s;
    cin>>s;

    string ans;
    ans+=s[0];
    s.erase(s.begin()+0);

    getpermutation(s,ans);
}