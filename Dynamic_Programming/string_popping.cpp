#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//babbbaaabb Yes
//remove same consecutive charachter of atleast length 2

//baba No

unordered_map<string,bool> mp;

bool ispossible(string s)
{
    if(s.empty())
    return true;

    if(mp[s]!=0)
    return mp[s];

    int i=0;
    bool f=false;

    while(i<s.size() && !f)
    {
        int j=i+1;

        while(j<s.size() && s[j]==s[i])
        j++;

        j--;

        if(j!=i)
        f=ispossible(s.substr(0,i)+s.substr(j+1));

        i=j+1;
    }

    return mp[s]=f;

}

int main()
{
    string s;
    cin>>s;

    if(ispossible(s))
    cout<<"Yes";
    else
    cout<<"NO";
}