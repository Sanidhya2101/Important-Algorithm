#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul long long int

/*first negative of the subarray of size k*/

vector<int> getfirstminimum(vector<int>& a,int k)
{
    vector<int> ans;
    deque<int> tmp;
    int i=0;

    for(int j=0;j<a.size();j++)
    {
        
        if(a[j]<0)
        tmp.push_back(a[j]);

        if(j-i+1==k)
        {
            
            if(tmp.empty())
            ans.push_back(0);

            else if(a[i]!=tmp.front())
            {
                ans.push_back(tmp.front());
            }
            else if(a[i]==tmp.front())
            {
                ans.push_back(tmp.front());
                tmp.pop_front();
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

    vector<int> ans=getfirstminimum(a,k);

    for(auto x:ans)
    cout<<x<<" ";
}
