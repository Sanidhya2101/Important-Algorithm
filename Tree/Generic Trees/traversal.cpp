#include<bits/stdc++.h>
using namespace std;

/*
24
10 20 50 -1 60 -1 -1 30 70 -1 80 110 -1 120 -1 -1 90 -1 -1 40 100 -1 -1 -1
*/


struct Node
{
    int data;
    vector<Node*> children;
};

Node* newNode(int x)
{
    Node* tmp=new Node;
    tmp->data=x;

    return tmp;
}

Node* construct(vector<int> a)
{
    Node* root=NULL;
    stack<Node*> s;

    for(int i=0;i<a.size();i++)
    {
        if(a[i]==-1)
        s.pop();
        else
        {
            Node* tmp=newNode(a[i]);
            if(s.size()>0)
            {
                s.top()->children.push_back(tmp);
            }
            else
            {
                root=tmp;
            }
            
            s.push(tmp);
        }
    }

    return root;
}

void traversals(Node *node)
{
    if(node==NULL)
    return;

    cout<<"Node Pre "<<node->data<<"\n";

    for(auto child:node->children)
    {
        cout<<"Edge Pre "<<node->data<<"--"<<child->data<<"\n";
        traversals(child);
        cout<<"Edge Post "<<node->data<<"--"<<child->data<<"\n";
    }

    cout<<"Node Post "<<node->data<<"\n";
    
}

void levelorder(Node *node)
{
    queue<Node*> q;
 
    q.push(node);

    while(!q.empty())
    {
        Node* tmp=q.front();
        q.pop();

        cout<<tmp->data<<" ";

        for(auto child:tmp->children)
        {
            q.push(child);
        }
    }    
}

int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }    


}