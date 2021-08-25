#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

struct node{
    int data;
    node* left;
    node* right;
};

node* create_tree(vector<int> a,int in)
{
    if(in>=a.size())
    return NULL;

    node* new_node = new node;
    new_node->data=a[in];

    new_node->left=create_tree(a,2*in+1);
    new_node->right=create_tree(a,2*in+2);

    return new_node;
}

void postorder_traversal_rec(node* root)
{
    if(root==NULL)
    return;

    postorder_traversal_rec(root->left);
    postorder_traversal_rec(root->right);

    cout<<root->data<<" ";
}

void postorder_traversal_itr(node* root)
{
    stack<node*> stacknode;

    stacknode.push(root);

    while(!stacknode.empty())
    {
        while(root)
        {
            if(root->right)
            stacknode.push(root->right);

            stacknode.push(root);

            root=root->left;
        }

        root=stacknode.top();
        stacknode.pop();

        if(root->right==stacknode.top())
        {
            stacknode.pop();
            stacknode.push(root);

            root=root->right;
        }
        else
        {
            cout<<root->data<<" ";
            root=NULL;
        }
    }
}

int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    node* root = create_tree(a,0);

    postorder_traversal_rec(root);

    cout<<"\n";

    postorder_traversal_itr(root);
}