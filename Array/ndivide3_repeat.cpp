#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//https://www.interviewbit.com/problems/n3-repeat-number/

int moore_voting(vector<int> a)
{
    int n=a.size();
    int cnt1=0;
    int cnt2=0;
    int ele1=0;
    int ele2=0;

    for(int i=0;i<n;i++)
    {
        if(ele1==a[i])
        cnt1++;
        else if(ele2==a[i])
        cnt2++;
        else if(cnt1==0)
        {
            cnt1++;
            ele1=a[i];
        }
        else if(cnt2==0)
        {
            cnt2++;
            ele2=a[i];
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    cnt1=0;
    cnt2=0;

    for(int i=0;i<n;i++)
    {
        if(ele1==a[i])
        cnt1++;
        if(ele2==a[i])
        cnt2++;
    }

    if(cnt1>n/3)
    return ele1;
    if(cnt2>n/3)
    return ele2;

    return -1;
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

    cout<<moore_voting(a);
}