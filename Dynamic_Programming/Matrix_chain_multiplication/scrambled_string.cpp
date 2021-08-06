#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//breakdown string into binary tree with no null node
//non-leaf  swapping of child 
//https://www.interviewbit.com/problems/scramble-string/

//   great
//  /    \
//  gr    eat           
// / \    /  \
// g   r  e   at
//           / \
//          a   t

//    rgtae
//   /    \
//  rg    tae
// / \    /  \
//r   g  ta  e
//       / \
//      t   a

unordered_map<string,bool> mp;

bool isscramble(string a,string b)
{
    if(a==b)
    return true;
    
    if(a.size()<=1)
    return false;

    string key=a+" "+b;

    if(mp.find(key)!=mp.end())
    return mp[key];


    int n=a.size();
    bool flag=false;

    for(int i=1;i<=n-1;i++)
    {
        if(isscramble(a.substr(0,i),b.substr(n-i,i)) && isscramble(a.substr(i,n-i),b.substr(0,n-i)))
        {
            flag=true;
            break;
        }

        if(isscramble(a.substr(0,i),b.substr(0,i)) && isscramble(a.substr(i,n-i),b.substr(i,n-i)))
        {
            flag=true;
            break;
        }
    }

    return mp[key]=flag;

}

int main()
{
    string a,b;
    cin>>a>>b;

    if(a.size()!=b.size())
    cout<<"NO";
    else if(a.empty() && b.empty())
    cout<<"YES";
    else if(isscramble(a,b))
    cout<<"YES";
    else
    cout<<"NO";


}