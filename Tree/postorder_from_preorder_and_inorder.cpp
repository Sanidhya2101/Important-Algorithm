#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

struct node{
    int data;
    node* left;
    node* right;
};

int preindex=0;

void printpostorder(vector<int> in,vector<int> pre,int start,int end,unordered_map<int,int> m)
{
    if(start>end)
    return;

    int in_index=m[pre[preindex++]];

    printpostorder(in,pre,start,in_index-1,m);

    printpostorder(in,pre,in_index+1,end,m);

    cout<<in[in_index]<<" ";
}

int pre_index=0;

node* build_tree(vector<int> in,vector<int> pre,int start,int end,unordered_map<int,int> m)
{
    if(start>end)
    return NULL;

    int element = pre[pre_index++];

    node* new_node = new node;

    new_node->data = element;

    if(start==end)
    return new_node;

    int in_index = m[element];

    new_node->left = build_tree(in,pre,start,in_index-1,m);

    new_node->right = build_tree(in,pre,in_index+1,end,m);

    return new_node;
}


void post_order(node* root)
{
    if(root==NULL)
    return;

    stack<node* > q;

    q.push(root);

    while(!q.empty())
    {
        while(root)
        {
            if(root->right)
            q.push(root->right);

            q.push(root);

            root=root->left;
        }

        root=q.top();
        q.pop();

        if(root->right==q.top())
        {
            q.pop();
            q.push(root);
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
    vector<int> pre,in;
    unordered_map<int,int> m;

    while(1)
    {
        int x;
        cin>>x;

        if(x==-1)
        break;

        pre.push_back(x);
    }

    while(1)
    {
        int x;
        cin>>x;

        if(x==-1)
        break;

        in.push_back(x);
    }    

    for(int i=0;i<in.size();i++)
    m[in[i]]=i;


    printpostorder(in,pre,0,in.size()-1,m);

    node* root = build_tree(in,pre,0,in.size()-1,m);


    cout<<"\n";

    post_order(root);

}