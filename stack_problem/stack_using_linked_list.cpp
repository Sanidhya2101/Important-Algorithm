#include<iostream>
using namespace std;

struct node{
    int x;
    node* prev;
};

class Stack{
    public:
    node* head;

    Stack()
    {
        head=NULL;
    }

    void push(int val)
    {
        node* new_node=new node;

        new_node->x=val;

        if(head==NULL)
        {
            new_node->prev=NULL;
            head=new_node;
        }
        else
        {
            new_node->prev=head;
            head=new_node;
        }
    }

    void pop()
    {
        if(head==NULL)
        {
            cout<<"Stack is empty"<<" ";
            return;
        }
        head=head->prev;
    }

    int top()
    {
        return head->x;
    }

    bool isempty()
    {
        if(head==NULL)
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
    //s.pop();

    while(!s.isempty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
