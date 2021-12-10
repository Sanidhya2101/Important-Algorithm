#include<bits/stdc++.h>
using namespace std;

//1 2 null 3 4 5

#define ll long long int
#define ul unsigned long int


struct Node{
    int data;
    Node* left;
    Node* right;
};

struct Node *create_node(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->right = node->left = NULL;
    return node;
}
Node* insert_node(Node* root,int n,queue<Node*> &q)
{
    Node* new_node = create_node(n);
    
    if(root==NULL)
    root=new_node;
    else if(q.front()->left==NULL)
    {
        q.front()->left=new_node;
    }
    else
    {
        q.front()->right=new_node;
        q.pop();
    }
    
    if(n!=INT_MAX)
    q.push(new_node);
    
    return root;
}

Node* remove_null(Node* root)
{
    if(root==NULL || root->data==INT_MAX)
    return NULL;
    
    root->left = remove_null(root->left);
    
    root->right = remove_null(root->right);
    
    return root;
}

int get_height(Node* root)
{
    if(root==NULL)
    return 0;

    int l=get_height(root->left);
    int r=get_height(root->right);

    return max(l,r)+1;

}


int main()
{
    string s;
    Node* root=NULL;
    queue<Node*> q;
    while(cin>>s)
    {
        if(s=="quit")
        break;
        else if(s=="null")
        root = insert_node(root,INT_MAX,q);
        else
        root = insert_node(root,stoi(s),q);
    }
    
    root = remove_null(root);
    
    cout<<get_height(root);
    
    //pre_order_traversal_rec(root);

    return 0;
}
