#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

int findmedian(int a[],int n)
{
    sort(a,a+n);
    return a[n/2];
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[],int start,int end,int med)
{
    int i;

    for(i=start;i<end;i++)
    {
        if(a[i]==med)
        break;

    }

    swap(&a[i],&a[end]);

    i=start;
    for(int j=start;j<=end-1;j++)
    {
        if(a[j]<=med)
        {
            swap(&a[i],&a[j]);
            i++;
        }
    }

    swap(&a[i],&a[end]);

    return i;
}

int getksmall(int a[],int start,int end,int k)
{
    if(k>0 && k<=end-start+1)
    {
        int n=end-start+1;

        int median[(n+4)/5];
        int i;
        for(i=0;i<n/5;i++)
        {
            median[i]=findmedian(a+start+i*5,5);
        }
        if(n%5!=0)
        median[i++]=findmedian(a+start+i*5,n%5);

        int medofmed=(i==1)?median[i-1]:getksmall(median,0,i-1,i/2);

        int pos = partition(a,start,end,medofmed);

        if(pos-start==k-1)
        return a[pos];
        if(pos-start>k-1)
        return getksmall(a,start,pos-1,k);

        return getksmall(a,pos+1,end,k-pos+start-1);
    }

    return -1;
}

int main()
{
    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++)
    cin>>a[i];

    int k;
    cin>>k;

    cout<<getksmall(a,0,n-1,k);    
}