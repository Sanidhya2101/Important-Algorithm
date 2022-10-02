#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int


int getans(vector<int> a)
{
    int n=a.size();
    vector<int> b=a;
    sort(b.begin(),b.end());

    if(b[n-1]==a[0])
    return a[0];

    int i=0;
    int j=n-1;

    while(i<n && b[i]==a[j])
    {
        n--;
        i++;
        j--;
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }

    if(sum%n==0)
    return sum/n;
    
    return sum/n+1;
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