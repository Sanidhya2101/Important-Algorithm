#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

ul mpow(ul a,ul b,ul m)
{
    a=a%m;

    ul res=1;

    while(b)
    {
        if(b&1)
        {
            res=(res*a)%m;
        }

        a=(a*a)%m;

        b>>=1;// b/2;
    }

    return res;
}


int main()
{
    ul a,b;

    cin>>a>>b;

    ul m=1e9+7;

    cout<<mpow(a,b,m)<<" ";

    cout<<pow(a,b);

}