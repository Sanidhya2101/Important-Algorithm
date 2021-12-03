#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

void getans(int s,int e,int n,int m,string tmp,vector<string> &ans)
{
    if(s==n-1 && e==m-1)
    {
        ans.push_back(tmp);
        return;
    }

    if(s<0 || s>=n || e<0 || e>=m)
    return;

    for(int i=1;i<n;i++)
    {
        getans(s+i,e,n,m,tmp+'v'+to_string(i),ans);
    }

    
    for(int i=1;i<n;i++)
    {
        getans(s,e+i,n,m,tmp+'h'+to_string(i),ans);
    }

    int i=1;
    int j=1;

    while(i<n && j<m)
    {
        getans(s+i,e+j,n,m,tmp+'d'+to_string(j),ans);
        i++;
        j++;
    }

}

int main()
{
    int n,m;
    cin>>n>>m;

    string tmp;
    vector<string> ans;

    getans(0,0,n,m,tmp,ans);

    for(auto x:ans)
    {
        cout<<"["<<x<<"] ";
    }
}