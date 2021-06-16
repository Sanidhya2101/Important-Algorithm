//given 1 to n numbers with one duplicate find the missing one
#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul long long int


int main()
{
    int n;
    cin>>n;

    int eq1=0;
    int eq2=0;
    int sum1=n*(n+1)/2;
    int sum2=n*(n+1)*(2*n+1)/6;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;

        eq1+=x;
        eq2+=x*x;
    }

    eq1-=sum1;
    eq2-=sum2;

    int eq3=eq2/eq1;

    cout<<"Missing : "<<(eq3-eq1)/2<<endl;
    cout<<"Duplicate : "<<(eq3+eq1)/2<<endl;



}