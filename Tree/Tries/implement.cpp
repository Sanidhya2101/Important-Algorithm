#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

struct Trie{
    char data;
    Trie* children[26];
    bool isend;
};

Trie* create_node(char c)
{
    Trie* new_node=new Trie;
    new_node->data=c;

    for(int i=0;i<26;i++)
    new_node->children[i]=NULL;

    new_node->isend=false;

    return new_node;
}

void insert_node(Trie* root,string s)
{
    Trie* node=root;

    for(int i=0;i<s.size();i++)
    {
        if(node->children[s[i]-'a']==NULL)
        node->children[s[i]-'a']=create_node(s[i]);

        node=node->children[s[i]-'a'];
    }
    node->isend=true;
}

bool search(Trie* root,string s,int x)
{
    Trie* node=root;

    for(int i=0;i<s.size();i++)
    {
        if(node->children[s[i]-'a']==NULL)
        return false;

        node=node->children[s[i]-'a'];
    }
    if(x==0)
    return node->isend;
    
    return true;
}


int main()
{
    int n;
    cin>>n;

    Trie* root=create_node(' ');

    while(n--)
    {
        char c;
        string s;
        cin>>c>>s;

        if(c=='i')
        insert_node(root,s);
        else
        {
            int x=0;
            if(c=='w')
            x=1;
            if(search(root,s,x))
            cout<<"YES ";
            else
            cout<<"NO ";
        }
    }
}