#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul long long int


//forxoxfrxofrdsorf  for ans=3
//aabaabaa  aaba    ans=4


int getanagram(string s,string p)
{
    unordered_map<char,int> m;
    unordered_map<char,int> x;

    int i=0,j=0;

    while(j<p.size())
    {
        m[s[j]]++;
        x[p[j]]++;
        j++;
    }
    j--;

    int cnt=0;

    while(j<s.size())
    {
        if(m==x)
        cnt++;

        j++;

        if(j!=s.size())
        m[s[j]]++;

        m[s[i]]--;
        if(m[s[i]]==0)
        m.erase(s[i]);

        i++;
    }

    return cnt;
}



int main()
{
    string s;
    string p;

    cin>>s>>p;

    cout<<getanagram(s,p);


}