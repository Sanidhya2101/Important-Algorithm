#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* new_node=new Node;
    new_node->data=val;
    new_node->left=new_node->right=NULL;
    return new_node;
}

Node* create_tree()
{
    string tmp;
    cin>>tmp;
    
    if(tmp=="#")
    return NULL;
    
    Node* node=newNode(stoi(tmp));
    
    node->left=create_tree();
    node->right=create_tree();
    
    return node;
}

vector<vector<int>> getvertical(Node* root)
{
    if(root==NULL)
    return {{}};

    vector<vector<int>> ans;

    map<int,vector<int>> mp;

    queue<pair<int,Node*>> q;

    q.push({0,root});

    while(!q.empty())
    {
        int n=q.size();

        for(int i=0;i<n;i++)
        {
            Node* node=q.front().second;
            int tmp=q.front().first;
            q.pop();

            mp[tmp].push_back(node->data);
            if(node->left)
            q.push({tmp-1,node->left});
            if(node->right)
            q.push({tmp+1,node->right});
        }
    }

    for(auto x:mp)
    {
        ans.push_back(x.second);    
    }

    return ans;
}


int main()
{
    Node* root=create_tree();
    
    unordered_map<int,vector<int>> mp;
    stack<Node*>s;
    
    for(auto x:getvertical(root))
    {
        for(auto y:x)
        {
            cout<<y<<" ";
        }
    }
    
}