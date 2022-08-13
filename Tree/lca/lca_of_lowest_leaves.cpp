#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/


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

int lca(Node* root,int curr,int h)
{
    if(root==NULL)
    return -1;

    if(curr==h)
    return root->data;

    int left_lca=lca(root->left,curr+1,h);
    int right_lca=lca(root->right,curr+1,h);

    if(left_lca!=-1 && right_lca!=-1)
    return root->data;

    if(left_lca!=-1)
    return left_lca;

    return right_lca;
}

int height(Node* root)
{
    if(root==NULL)
        return 0;
    
    int left=height(root->left);
    int right=height(root->right);
    
    return max(left,right)+1;
}


int main()
{
    build_tree(&root);
    int a,b;
    cin>>a>>b;

    int h=height(root);

    cout<<lca(root,0,h);
}