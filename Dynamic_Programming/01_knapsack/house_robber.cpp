#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//https://leetcode.com/problems/house-robber-ii/


int getans(vector<int> a)
{
    int n=a.size();

    int f=a[0];
    int s=max(a[0],a[1]);

    for(int i=2;i<n-1;i++)
    {
        int tmp=max(f+a[i],s);
        f=s;
        s=tmp;
    }

    int f1=a[1];
    int s1=a[2];

    for(int i=3;i<n;i++)
    {
        int tmp=max(f1+a[i],s1);
        f1=s1;
        s1=tmp;
    }

    return max(s1,s);
}


int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    cout<<getans(a);

}