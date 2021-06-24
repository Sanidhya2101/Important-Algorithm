#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul long long int


int main()
{
    int n;
    cin>>n;

    vector<string> s(n);
    unordered_map<string,vector<string>> m;

    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        string q=s[i];
        string p=".";
        for(int j=1;j<q.size();j++)
        {
            if(q[j]>q[j-1])
            p+=to_string(q[j]-q[j-1]);
            else
            p+=to_string(q[j]-q[j-1]+26);

            p+="#";
        }


        m[p].push_back(q);
    }
    

    for(auto x:m)
    {
        for(auto y:x.second)
        cout<<y<<" ";
        cout<<"\n";
    }

}