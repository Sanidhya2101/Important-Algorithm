#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

struct node{
    int data;
    node* left;
    node* right;
};

node* build_tree(node* root,int n)
{
    if(root==NULL)
    {
        node* new_node = new node;
        new_node->data=n;
        new_node->left=new_node->right=NULL;
        return new_node;
    }

    if(n<root->data)
    root->left=build_tree(root->left,n);
    else
    root->right=build_tree(root->right,n);

    return root;

}

void post_order(node* root)
{
    stack<node*> s;

    s.push(root);

    while(!s.empty())
    {
        while(root)
        {
            if(root->right)
            s.push(root->right);
            
            s.push(root);

            root=root->left;
        }

        root=s.top();

        s.pop();

        if(root->right==s.top())
        {
            s.pop();
            s.push(root);

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

    node* root=NULL;

    for(int i=0;i<n;i++)
    {
        root=build_tree(root,a[i]);
    }

    post_order(root);
}