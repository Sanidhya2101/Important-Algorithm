#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

int getans(string s,string p)
{
    if(s==p)
    return 1;

    if(s.size()!=p.size())
    return 0;

    unordered_set<char> sc;

    for(int i=0;i<p.size();i++)
    sc.insert(p[i]);

    if(sc.size()==26)
    return 0;

    unordered_map<char,char> mp;


    for(int i=0;i<s.size();i++)
    {
        if(mp.count(s[i])==0)
        mp[s[i]]=p[i];
        else
        {
            if(mp[s[i]]!=p[i])
            return 0;
        }
    }

    return 1;
}

int main()
{
    string s,p;

    cin>>s>>p;

    cout<<getans(s,p);
}