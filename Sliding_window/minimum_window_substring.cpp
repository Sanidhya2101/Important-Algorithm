#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul long long int

string getminsubstring(string s,string p)
{
    string ans;

    unordered_map<char,int> m;
    vector<int> a(2);

    for(auto x:p)
    m[x]++;


    int i=0;
    int j=0;

    int q=m.size();
    int cnt=s.size();

    while(j<s.size())
    {
        m[s[j]]--;

        if(m[s[j]]==0)
        q--;

        if(q==0)
        {
            while(q==0)
            {
                if(cnt>j-i+1)
                {
                    cnt=j-i+1;
                    a={i,j};
                }
                m[s[i]]++;
                if(m[s[i]]>0)
                q++;

                i++;
            }
        }
        j++;
    }

    for(int k=a[0];k<=a[1];k++)
    ans+=s[k];

    return ans;
}


int main()
{
    string s,p;
    cin>>s>>p;


    cout<<getminsubstring(s,p);
}