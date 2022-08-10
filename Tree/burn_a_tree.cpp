#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//1 2 3 4 5 null -1

//https://www.interviewbit.com/problems/burn-a-tree/

struct Node
{
    int data;
    struct Node *left, *right;
} *root1 = NULL, *root2 = NULL;

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

int burn(Node* root,int target,int &depth,int &ans)
{
    if(root==NULL)
    return 0;

    if(root->data==target)
    {
        depth=1;
        return 1;
    }

    int ld=-1;
    int rd=-1;

    int lh=burn(root->left,target,ld,ans);
    int rh=burn(root->right,target,rd,ans);

    if(ld!=-1)
    {
        ans=max(ans,ld+1+rh);
        depth=ld+1;
    }
    else if(rd!=-1)
    {
        ans=max(ans,rd+1+lh);
        depth=rd+1;
    }

    return max(lh,rh)+1;
}


int main()
{
    build_tree(&root1);
    int target;
    cin>>target;

    int ans=0;
    int depth=-1;
    burn(root1,target,depth,ans);
    cout<<ans;
}
