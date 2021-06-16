//not for read only array
//given 1 to n number find duplicate and missing ones

//8
//3 2 1 8 2 3 5 1

#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul long long int


void swap(int* a,int* b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}


int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    for(int i=0;i<n;i++)
    {
        if(a[i]==i+1)continue;
        else
        {
            if(a[i]!=a[a[i]-1])
            {
                swap(&a[i],&a[a[i]-1]);
                i--;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i+1!=a[i])
        {
            cout<<"Missing : "<<i+1<<endl;
            cout<<"Duplicate :"<<a[i]<<" ";
            cout<<"\n\n";

        }
    }
}