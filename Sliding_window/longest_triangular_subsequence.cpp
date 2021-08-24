#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int


int getans(vector<int> a)
{
    int ans=0;

    int i=0;

    sort(a.begin(),a.end());

    while(i<a.size())
    {
        for(int j=i+1;j<a.size();j++)
        {
            int cnt=2;
            for(int k=j+1;k<a.size() && a[i]+a[j]>a[k];k++)
            cnt++;

            if(cnt!=2)
            ans=max(ans,cnt);

        }

        i++;
        
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


    cout<<getans(a);
}