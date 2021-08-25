#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

struct node{

    int data;
    node* left;
    node* right;
};

struct node *Build_tree(vector<int> a,int in)
{
    if(in>=a.size())
    return NULL;

    node* new_node = new node;
    new_node->data=a[in];

    new_node->left=Build_tree(a,2*in+1);
    new_node->right=Build_tree(a,2*in+2);

    return new_node;
};

void pre_order_traversal_rec(node* root)
{
    if(root==NULL)
    return;

    cout<<root->data<<" ";

    pre_order_traversal_rec(root->left);

    pre_order_traversal_rec(root->right);
}

void pre_order_traversal_ite(node* root)
{
    if(root==NULL)
    return;

    stack<node*> nodestack;

    nodestack.push(root);

    while(!nodestack.empty())
    {
        node* tmp = nodestack.top();
        nodestack.pop();

        cout<<tmp->data<<" ";

        if(tmp->right)
        nodestack.push(tmp->right);

        if(tmp->left)
        nodestack.push(tmp->left);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    int tmp=n;
    
    for(int i=0;i<n;i++)
    cin>>a[i];

    node* root = Build_tree(a,0);

    pre_order_traversal_rec(root);
    cout<<"\n";

    pre_order_traversal_ite(root);
}