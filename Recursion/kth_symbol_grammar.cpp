#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//0
//01
//0110
//01101001
//0110100110010110

int getkgrammar(int n,int k)
{

    if(n==1 && k==1)
    return 0;

    int mid=pow(2,n-1)/2;        

    if(k<=mid)
    return getkgrammar(n-1,k);
    else
    return 1-getkgrammar(n-1,k-mid);

}


int main()
{
    int n,k;
    cin>>n>>k;

    cout<<getkgrammar(n,k);

}