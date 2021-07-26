#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int


void delete_stack(stack<int> &s,int n,int &k)
{
    if(k==n/2)
    {
        s.pop();
        return;
    }

    int temp=s.top();
    k++;
    s.pop();

    delete_stack(s,n,k);

    s.push(temp);
}

int main()
{
    int n;
    cin>>n;

    stack<int> s;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s.push(x);
    }
    int k=0;
    if(s.size()%2==0)
    k=1;
    delete_stack(s,s.size(),k);

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}