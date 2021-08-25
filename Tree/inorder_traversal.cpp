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

void inorder_traversal_rec(node* root)
{
    if(root==NULL)
    return;

    inorder_traversal_rec(root->left);

    cout<<root->data<<" ";

    inorder_traversal_rec(root->right);
}

void inorder_traversal_itr(node* root)
{
    stack<node*> stacknode;

    while(root!=NULL || !stacknode.empty())
    {
        while(root)
        {
            stacknode.push(root);
            root=root->left;
        }

        root=stacknode.top();
        stacknode.pop();
        cout<<root->data<<" ";
        root=root->right;
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

    inorder_traversal_rec(root);

    cout<<"\n";

    inorder_traversal_itr(root);

}