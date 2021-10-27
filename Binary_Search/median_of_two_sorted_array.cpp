#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//https://leetcode.com/problems/median-of-two-sorted-arrays/

double getmedian(vector<int> a,vector<int> b)
{
    if(a.size()>b.size())
    return getmedian(b,a);

    int l=0;
    int r=a.size()-1;

    int n=a.size()+b.size();

    while(true)
    {
        int i=floor(l+(r-l)/2.0);
        int j=n/2-i-2;

        int aleft = i>=0?a[i]:INT_MIN;
        int aright = i+1<a.size()?a[i+1]:INT_MAX;

        int bleft = j>=0?b[j]:INT_MIN;
        int bright = j+1<b.size()?b[j+1]:INT_MAX;

        if(aleft<=bright && bleft<=aright)
        {
            if(n%2==0)
            return (max(aleft,bleft)+min(aright,bright))/2.0;
            else
            return min(aright,bright)/1.0;
        }
        else if(aleft>bright)
        r=i-1;
        else
        l=i+1;
    }
}


int main()
{
    int n,m;
    cin>>n>>m;

    vector<int> a(n),b(m);

    for(int i=0;i<n;i++)
    cin>>a[i];

    for(int i=0;i<m;i++)
    cin>>b[i];

    cout<<getmedian(a,b);
}