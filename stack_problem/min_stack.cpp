#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul long long int

//with extra space

class min_stack_{
    public:
    stack<int> s,support_s;


    void push(int x)
    {
        s.push(x);
        if(support_s.empty())
        support_s.push(x);
        else if(support_s.top()>=x)
        support_s.push(x);
    }

    void pop()
    {
        if(s.top()==support_s.top())
        support_s.pop();
        s.pop();
    }

    int getmin()
    {
        return support_s.top();
    }

};

//with constant space
class min_stack{
    public:
    stack<int> s;
    int Min;

    void push(int x)
    {
        if(s.empty())
        {
            s.push(x);
            Min=x;
        }
        else
        {
            if(s.top()<x)
            s.push(x);
            else
            {
                s.push(2*x-Min);
                Min=x;
            }
        }
    }

    void pop()
    {
        if(s.top()>Min)
        s.pop();
        else
        {
            Min=2*Min-s.top();
            s.pop();
        }
    }

    int top()
    {
        if(s.top()>Min)
        return s.top();
        else
        return Min;
    }

    int getmin()
    {
        return Min;
    }

};

int main()
{

    min_stack s;

    int x=0;
    while(x!=-1)
    {
        cin>>x;
        if(x==-1)
        break;
        s.push(x);
    }

    cout<<s.getmin()<<"\n";

    s.pop();

    cout<<s.getmin()<<"\n";
}