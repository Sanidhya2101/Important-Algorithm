#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//https://leetcode.com/problems/stream-of-characters/

class Trie{
    Trie* children[26];
    bool isend=false;

    public:

    bool iscontains(char c)
    {
        return children[c-'a']!=NULL;
    }
    
    void put(char c,Trie* newNode)
    {
        children[c-'a']=newNode;
    }

    Trie* getnext(char c)
    {
        return children[c-'a'];
    }

    bool checkend()
    {
        return isend;
    }

    void putend()
    {
        isend=true;
    }
};


class Streamchecker{

    string s;
    Trie* root;

    void insert(string p)
    {
        Trie* tmp=root;

        for(int i=p.size()-1;i>=0;i--)
        {
            if(!tmp->iscontains(p[i]))
            tmp->put(p[i],new Trie());

            tmp=tmp->getnext(p[i]);
        }

        tmp->putend();
    }

    public:

    Streamchecker(vector<string> words)
    {
        root=new Trie();

        for(auto x:words)
        insert(x);
    }

    bool query(char c)
    {
        s+=c;
        Trie* tmp=root;

        for(int i=s.size()-1;i>=0 && tmp;i--)
        {
            if(!tmp && !tmp->iscontains(s[i]))
            return false;

            tmp=tmp->getnext(s[i]);

            if(tmp && tmp->checkend())
            return true;
        }

        return false;
    }

};

int main()
{
    int n;
    cin>>n;

    vector<string> a(n);

    for(int i=0;i<n;i++)
    cin>>a[i];

    Streamchecker* ss = new Streamchecker(a);

    bool f1 = ss->query('a');

    bool f2 = ss->query('x');

    bool f3 = ss->query('y');

    bool f4 = ss->query('z');

    if(f4)
    cout<<1;
    else
    cout<<0;

}