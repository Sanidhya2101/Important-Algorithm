#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int


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


vector<int> node_to_rootpath(Node* node,int data)
{
    if(node->data==data)
    {
        return {node->data};
    }

    for(auto child:node->children)
    {
        vector<int> a=node_to_rootpath(child,data);
        if(a.size()>0)
        {
            a.push_back(node->data);
            return a;
        }
    }

    return {};
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

    int data;
    cin>>data;

    Node* root = construct(a);



}