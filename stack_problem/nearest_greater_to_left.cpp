#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul long long int

vector<int> getgreater(vector<int>& a)
{
    vector<int> ans;

    ans.push_back(-1);

    stack<int> s;

    s.push(a[0]);

    for(int i=1;i<a.size();i++)
    {
        if(a[i]<s.top())
        {
            ans.push_back(s.top());
            s.push(a[i]);
        }
        else
        {
            while(!s.empty() && a[i]>s.top())
            {
                s.pop();
            }
            if(s.empty())
            ans.push_back(-1);
            else
            ans.push_back(s.top());

            s.push(a[i]);
        }
    }

    return ans;
}


int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    vector<int> ans=getgreater(a);

    for(auto x:ans)
    cout<<x<<" "; 
}