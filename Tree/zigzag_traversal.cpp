#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int x)
{
    Node* new_node=new Node;
    new_node->data=x;
    new_node->left=new_node->right=NULL;
    return new_node;
}

Node* create()
{
    string val;
    cin>>val;
    
    if(val=="#")
    return NULL;
    
    Node* root=newNode(stoi(val));
    root->left=create();
    root->right=create();
    return root;
}

vector<vector<int>> getans(Node* root)
{
    if(root==NULL)
    return {{}};

    vector<vector<int>> ans;

    queue<Node*> q;

    q.push(root);

    bool lefttoright=true;

    while(!q.empty())
    {
        int n=q.size();

        vector<int> tmp(n);

        for(int i=0;i<n;i++)
        {
            Node* node=q.front();
            q.pop();

            int in=(lefttoright)?i:n-i-1;
            tmp[i]=node->data;
            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);
        }

        lefttoright=!lefttoright;
        ans.push_back(tmp);
    }
}


int main()
{
    Node* root=create();
    
    vector<vector<int>> ans=getans(root);
    
    for(auto x:ans)
    {
        for(auto y:x)
        cout<<y<<" ";
    }
}