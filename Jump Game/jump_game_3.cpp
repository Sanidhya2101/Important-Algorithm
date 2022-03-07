#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//https://leetcode.com/problems/jump-game-iii/

bool getans(vector<int> a,int start)
{
    if(a[start]==0)
    return true;

    if(a[start]==-1)
    return false;

    bool f=false;

    int j=a[start];
    a[start]=-1;

    if(start+j<a.size())
        f|=getans(a,start+j);
    
    if(start-j>=0)
        f|=getans(a,start-j);

    
    return f;
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

    int start;
    cin>>start;

    cout<<getans(a,start);
}