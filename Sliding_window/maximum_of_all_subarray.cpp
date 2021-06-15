#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul long long int

//use of list to keep track of maximum

vector<int> getmax(vector<int>& a,int k)
{
    vector<int> ans;
    list<int> l;


    int i=0;

    for(int j=0;j<a.size();j++)
    {
        if(j-i+1<k)
        {
            
            while(!l.empty() && l.front()<a[j])
            {
                l.pop_front();
            }
            
            l.push_back(a[j]);
            
            
        }
        else if(j-i+1==k)
        {
            while(!l.empty() && l.front()<a[j])
            {
                l.pop_front();
            }
        
            l.push_back(a[j]);
    
            ans.push_back(l.front());
            
            if(a[i]==l.front())
            {
                l.pop_front();
            }

            i++;
        }
    }

    return ans;
}


int main()
{
    int n,k;
    cin>>n>>k;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    vector<int> b=getmax(a,k);

    for(auto x:b)
    cout<<x<<" ";
}