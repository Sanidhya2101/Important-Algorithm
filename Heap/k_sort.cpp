#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//given k nearly sorted array

vector<int> getksorted(vector<int>& a,int k)
{
    vector<int> ans;

    priority_queue<int,vector<int>,greater<int>> p;

    for(int j=0;j<a.size();j++)
    {
        p.push(a[j]);

        if(p.size()==k)
        {
            ans.push_back(p.top());
            p.pop();
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
    cin>>a[i];

    int k;
    cin>>k;

    for(auto x:getksorted(a,k))
    cout<<x<<" ";

}