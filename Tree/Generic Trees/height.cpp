#include<bits/stdc++.h>
using namespace std;

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

int height(Node* node)
{
    if(node->children.empty())
    return 0;

    int h=INT_MIN;

    for(auto child:node->children)
    {
        h=max(h,height(child)+1);
    }

    return h;
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