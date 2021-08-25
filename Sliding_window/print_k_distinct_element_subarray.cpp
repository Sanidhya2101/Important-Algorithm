#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul long long int

//get total subarray of atmost k distinct element and subtract it with totatl subarray of atmost k-1 and get
//total subarray with k distinct element

int getsub(vector<int>& a,int k)
{
    int ans=0;
    unordered_map<int,int> m;

    int i=0;
    for(int j=0;j<a.size();j++)
    {
        m[a[j]]++;
        if(m.size()<=k)
        {
            ans+=j-i+1;
        }
        else
        {
            while(!m.empty() && m.size()>k)
            {
                m[a[i]]--;
                if(m[a[i]]==0)
                m.erase(a[i]);
                i++;
            }
            ans+=j-i+1;
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

    cout<<getsub(a,k)-getsub(a,k-1);
}