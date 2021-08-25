#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul long long int

/*subarray of size k with condition to get something maximum and minimum*/
/*two types : window fixed sized and variable size*/

/*max sum of subarray of size k*/

int getmax(vector<int>& a,int k)
{
    int tmp=0;

    for(int i=0;i<k;i++)
    tmp+=a[i];

    int i=0;
    int j=k;

    int sum=tmp;

    while(j<a.size())
    {
        tmp-=a[i++];
        tmp+=a[j++];
        sum=max(sum,tmp);
    }

    return sum;
}


int main()
{
    int n,k;
    cin>>n>>k;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    cout<<getmax(a,k);
}