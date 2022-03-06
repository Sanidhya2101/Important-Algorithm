#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//leetcode.com/problems/jump-game/


bool canreach(vector<int> a)
{
    int maxi=0;

    for(int i=0;i<a.size();i++)
    {
        if(maxi>=i)
        maxi=max(maxi,i+a[i]);
    }

    return maxi>=a.size()-1;
}


int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    cout<<canreach(a);
}