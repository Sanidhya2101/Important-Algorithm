//3 0 0 2 0 4
//1 0 2 1 0 1 3 2 1 2 1

#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul long long int

int getmaxwater(vector<int>& a)
{
    int ans=0;

    vector<int> left;
    left.push_back(a[0]);    
    for(int i=1;i<a.size();i++)
    {
        if(a[i]>left[i-1])
        {
            left.push_back(a[i]);
        }
        else
        {
            left.push_back(left[i-1]);
        }
    }

    vector<int> right(a.size());

    right[a.size()-1]=a[a.size()-1];

    for(int i=a.size()-2;i>=0;i--)
    {
        if(a[i]>right[i+1])
        right[i]=a[i];
        else
        right[i]=right[i+1];
    }


    for(int i=0;i<a.size();i++)
    {
        ans+=min(left[i],right[i])-a[i];
        //cout<<ans<<" ";
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

    cout<<getmaxwater(a);
}