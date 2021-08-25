#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul long long int

//pwwkew

//aabacebebebe

string getsubstring(string s)
{
    string ans;
    int cnt=0;

    vector<int> a(2);

    int i=0;
    int j=0;

    unordered_map<char,int> m;

    while(j<s.size())
    {
        m[s[j]]++;

        if(m.size()==j-i+1)
        {
            if(cnt<j-i+1)
            {
                cnt=m.size();
                a={i,j};
            }
            j++;
        }
        else
        {
            while(m.size()!=j-i+1)
            {
                m[s[i]]--;

                if(m[s[i]]==0)
                m.erase(s[i]);

                i++;
            }
            if(m.size()==j-i+1)
            {
                if(cnt<m.size())
                {
                    cnt=m.size();
                    a={i,j};

                }
            }
            j++;
        }

    }

    for(int k=a[0];k<=a[1];k++)
    ans+=s[k];


    return ans;
}

int main()
{
    string s;
    cin>>s;

    cout<<getsubstring(s);
}