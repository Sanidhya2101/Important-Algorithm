#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul long long int

//get substring with k unique charachter

//aabacebebebe k=3

int getsubstring(string s,int k)
{
    int ans=0;

    int i=0;
    int j=0;

    unordered_map<char,int> m;

    while(j<s.size())
    {
        m[s[j]]++;

        if(m.size()<k)
        {
            j++;
        }
        else if(m.size()==k)
        {
            ans=max(ans,j-i+1);
            j++;
        }
        else
        {
            while(m.size()>k)
            {
                m[s[i]]--;
                if(m[s[i]]==0)
                m.erase(s[i]);
                i++;
            }
            if(m.size()==k)
            ans=max(ans,j-i+1);

            j++;
        }
        

    }

    return ans;
}

int main()
{
    string s;
    cin>>s;

    int k;
    cin>>k;

    cout<<getsubstring(s,k);
}