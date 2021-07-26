#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int


void insert(stack<int> &s,int temp)
{
    if(s.empty())
    {
        s.push(temp);
        return;
    }

    int val=s.top();
    s.pop();
    insert(s,temp);

    s.push(val);
}

void reverse_stack(stack<int> &s)
{
    if(s.size()==0)
    return;

    int temp=s.top();
    s.pop();

    reverse_stack(s);

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

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}