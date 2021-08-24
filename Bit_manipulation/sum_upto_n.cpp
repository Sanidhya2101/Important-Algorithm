#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int
#define mod 1000000007

int main()
{
    int n;
    cin>>n;

    int ans=0;

    int one=1;

    while(1)
    {
        if(n<=1)
        {
            ans=ans+n;
            break;
        }

        int x=log2(n);

        int cur=0;

        int add=(one<<(x-1));

        for(int i=1;i<=x;i++)
        {
            cur=(cur+add);
            add=(add*10);
        }

        ans=ans+cur;

        int rem=n-(one<<x)+1;

        int p=pow(10,x);

        p=(p*rem);

        ans=ans+p;

        n=rem-1;
    }

    cout<<ans;


}