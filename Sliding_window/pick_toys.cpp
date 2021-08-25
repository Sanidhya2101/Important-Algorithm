//to select 2 types of toys of any quantity in continuouns manner

#include<bits/stdc++.h>
using namespace std;


int gettoys(string s)
{
    int ans=0;

    int i=0;
    int j=0;

    unordered_map<char,int> m;


    while(j<s.size())
    {
        m[s[j]]++;

        if(m.size()<2)
        j++;
        else if(m.size()==2)
        {
            ans=max(ans,j-i+1);
            j++;
        }
        else
        {
            while(m.size()>2)
            {
                m[s[i]]--;
                if(m[s[i]]==0)
                m.erase(s[i]);
                i++;
            }
            if(m.size()==2)
            {
                ans=max(ans,j-i+1);
            }
            j++;
        }

    }   

    return ans;
}


#define ll long long int
#define ul long long int


int main()
{
    string s;

    cin>>s;

    cout<<gettoys(s);
}