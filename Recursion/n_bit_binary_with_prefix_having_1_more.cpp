#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

void getans(int one,int zero,string out,int n)
{

    if(one>zero)
    return;


    if(one+zero==n)
    {
        cout<<out<<"\n";
        return;
    }


    if(one!=0)
    getans(one-1,zero,out+"1",n);
    if(zero!=0)
    getans(one,zero-1,out+"0",n);

}


int main()
{
    int n;
    cin>>n;

    string ans;

    getans(n,n,ans,n);
}