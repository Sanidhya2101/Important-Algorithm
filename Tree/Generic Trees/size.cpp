#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    vector<Node*> children;
};

Node *newNode(int key)
{
	Node *temp=new Node;
	temp->data=key;
	return temp;
}

Node *construct(vector<int> a,int n )
{
    Node *root=NULL;

    stack<Node*>st;

    for(int i=0;i<n;i++)
    {
        if(a[i]==-1)
        {
            st.pop();
        }
        else
        {
            Node *t=newNode(a[i]);

            if(st.size()>0)
            {
                st.top()->children.push_back(t);
            }
            else
            {
                root=t;
            }
            st.push(t);
        }
    }

    return root;
}

int size(Node *node){
  
    if(node->children.empty())
    return 1;

    int cnt=0;

    for(auto child:node->children)
    {
        cnt+=size(child);
    }

    return cnt+1;


}

int main(){
    
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node *root=construct(arr,n);

    int sz=size(root);
    cout<<sz<<endl;
   //display(root);
}