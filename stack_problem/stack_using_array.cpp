#include<iostream>
using namespace std;

class Stack{

    public:
    int a[10000];
    int t;

    Stack()
    {
        t=-1;
    }

    void push(int x)
    {
        t++;
        a[t]=x;
    }
    void pop()
    {
        if(t==-1)
        {
            cout<<"Stack is empty"<<endl;
            return;
        }
        t--;
    }


    int top()
    {
        return a[t];
    }

    bool isempty()
    {
        if(t==-1)
        return true;
        else
        return false;
    }


};


int main()
{
    Stack s;

    s.push(1);

    s.push(2);

    s.push(3);

    s.pop();

    s.push(6);

    while(!s.isempty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}