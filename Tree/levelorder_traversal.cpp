#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

struct node{
    int data;
    node* left;
    node* right;
};  

node* Create_tree(vector<int> a,int in)
{
    if(in>=a.size())
    return NULL;

    node* new_node = new node;

    new_node->data=a[in];

    new_node->left = Create_tree(a,2*in+1);

    new_node->right = Create_tree(a,2*in+2);

    return new_node;
}

void levelorder_traversal(node* root)
{

    if(root==NULL)
    return;

    
    queue<node*> q;

    q.push(root);

    while(!q.empty())
    {
        node* tmp = q.front();

        q.pop();

        if(tmp->left)
        q.push(tmp->left);

        if(tmp->right)
        q.push(tmp->right);

        cout<<tmp->data<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    node* root = Create_tree(a,0);

    levelorder_traversal(root);
}