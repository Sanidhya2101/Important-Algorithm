#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int


//1 2 3 4 5 null -1

//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

struct Node
{
    int data;
    struct Node *left, *right;
} *root = NULL;

struct Node *create_node(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

Node *remove_null_nodes(Node *root)
{
    if (root == NULL || root->data == INT_MAX)
        return NULL;

    root->left = remove_null_nodes(root->left);
    root->right = remove_null_nodes(root->right);

    return root;
}

Node *insert_node(Node *root, int value, queue<Node *> &queue)
{
    Node *new_node = create_node(value);
    if (root == NULL)
        root = new_node;
    else if (queue.front()->left == NULL)
        queue.front()->left = new_node;
    else
    {
        queue.front()->right = new_node;
        queue.pop();
    }

    if (value != INT_MAX)
        queue.push(new_node);
    return root;
}

void build_tree(struct Node **root)
{
    string temp;
    queue<Node *> queue;
    while (1)
    {
        cin >> temp;
        if (temp == "-1")
            break;

        if (temp == "null")
            *root = insert_node(*root, INT_MAX, queue);
        else
            *root = insert_node(*root, stoi(temp), queue);
    }
    *root = remove_null_nodes(*root);
    return;
}

int lca(Node* root,int a,int b)
{
    if(root==NULL)
    return -1;

    if(root->data>a && root->data>b)
    return lca(root->left,a,b);

    if(root->data<a && root->data<b)
    return lca(root->right,a,b);

    return root->data;
}



int main()
{
    build_tree(&root);
    int a,b;
    cin>>a>>b;

    cout<<lca(root,a,b);
}