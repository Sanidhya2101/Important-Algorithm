#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int


void insert(stack<int> &s,int temp)
{
    if(s.size()==0 || s.top()<=temp)
    {
        s.push(temp);
        return;
    }

    int val=s.top();
    s.pop();
    insert(s,temp);

    s.push(val);
}

void stack_sort(stack<int> &s)
{
    if(s.size()==1)
    return;

    int temp=s.top();

    s.pop();

    stack_sort(s);

    insert(s,temp);
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

    stack_sort(s);

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }


}