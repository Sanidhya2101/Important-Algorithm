//given 1 to n numbers with one duplicate find the missing one
#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul long long int


// long has to use
void using_sum_diff(int n)
{
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

void using_xor(int n)
{
    vector<int> a(n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int xo = 0;

    for(int i=0;i<n;i++)
    {
        xo^=a[i];
        xo^=(i+1);
    }

    int rbit = log2(xo & -xo);
    int xo1=0;
    int xo2=0;
    for(int i=0;i<n;i++)
    {
        if((a[i]&(1<<rbit)))
        xo1^=a[i];
        else
        xo2^=a[i];

        if((i+1)&(1<<rbit))
        xo1^=(i+1);
        else
        xo2^=(i+1);
    }
    int mis=-1,rep=-1;
    for(int i=0;i<n;i++)
    {
        if(xo1==a[i])
        {   
            cout<<"Missing : "<<xo2<<endl;
            cout<<"Duplicate : "<<xo1<<endl;  
            return;      
        }
        if(xo2==a[i])
        {
            cout<<"Missing : "<<xo1<<endl;
            cout<<"Duplicate : "<<xo2<<endl;  
            return;
        }
    }
    
}


int main()
{
    int n;
    cin>>n;

    using_sum_diff(n);
    using_xor(n);    
}

