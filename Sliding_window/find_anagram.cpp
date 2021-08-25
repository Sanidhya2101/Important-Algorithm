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

    int i=0;
    int cnt=0;

    for(int i=0;i<p.size();i++)
    {
        m[p[i]]++;
        x[p[i]]++;
    }

    i=0;

    int q=m.size();

    for(int j=0;j<s.size();j++)
    {
        if(j-i+1<p.size())
        {
            if(x[s[j]]!=0)
            {
                m[s[j]]--;
                
                if(m[s[j]]==0)
                q--;
            }


        }
        else if(j-i+1==p.size())
        {
            if(x[s[j]]!=0)
            {
                m[s[j]]--;

                if(m[s[j]]==0)
                q--;
            }


            if(q==0)
            cnt++;

            if(x[s[i]]!=0)
            {
                m[s[i]]++;
                if(m[s[i]]!=0)
                q++;
            }
            i++;
        }
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