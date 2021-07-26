#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

void getsubsets(string s,string out)
{
    if(s.size()==0)
    {
        cout<<out<<"\n";
        return;
    }

    char c=s[0];

    s.erase(s.begin()+0);

    getsubsets(s,out);
    getsubsets(s,out+c);
}


int main()
{
    string s;
    cin>>s;

    string ans;
    getsubsets(s,ans);
}