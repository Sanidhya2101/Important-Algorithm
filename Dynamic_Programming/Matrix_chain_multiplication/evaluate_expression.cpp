#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

//| & ^ this symbol will be given
//1^0&1 - 2
//minimum number of ways to get true

//1|1&0^1 - 4


unordered_map<string,int> mp;

int getvalue(string s,int i,int j,bool exp)
{
    if(i>j)
    return 0;

    if(i==j)
    {
        if(exp==true)
        return s[i]=='1';
        else
        return s[i]=='0';
    }

    int ans=0;

    for(int k=i+1;k<j;k+=2)
    {
        int lt=getvalue(s,i,k-1,true);
        int lf=getvalue(s,i,k-1,false);
        int rt=getvalue(s,k+1,j,true);
        int rf=getvalue(s,k+1,j,false);

        if(s[k]=='&')
        {
            if(exp==true)
            ans+=lt*rt;
            else
            ans+=lt*rf+rt*lf+rf*lf;
        }

        else if(s[k]=='|')
        {
            if(exp==true)
            ans+=lt*rt+lt*rf+lf*rt;
            else
            ans+=lf*rf;
        }
        else
        {
            if(exp==true)
            ans+=lt*rf+lf*rt;
            else
            ans+=lf*rf+lt*rt;
        }
    }

    return ans;
}

string getstring(int i,int j,bool exp)
{
    string s;
    s+=to_string(i);
    s+=' ';
    s+=to_string(j);
    s+=' ';
    if(exp)
    s+='1';
    else
    s+='0';

    return s;
}


int getvalue_memoization(string s,int i,int j,bool exp)
{
    if(i>j)
    return 0;

    if(i==j)
    {
        if(exp==true)
        return s[i]=='1';
        else
        return s[i]=='0';
    }

    string tmp=getstring(i,j,exp);

    if(mp.find(tmp)!=mp.end())
    return mp[tmp];

    int ans=0;

    for(int k=i+1;k<j;k+=2)
    {
        int lt=getvalue(s,i,k-1,true);
        int lf=getvalue(s,i,k-1,false);
        int rt=getvalue(s,k+1,j,true);
        int rf=getvalue(s,k+1,j,false);

        if(s[k]=='&')
        {
            if(exp==true)
            ans+=lt*rt;
            else
            ans+=lt*rf+rt*lf+rf*lf;
        }

        else if(s[k]=='|')
        {
            if(exp==true)
            ans+=lt*rt+lt*rf+lf*rt;
            else
            ans+=lf*rf;
        }
        else
        {
            if(exp==true)
            ans+=lt*rf+lf*rt;
            else
            ans+=lf*rf+lt*rt;
        }
    }

    return mp[tmp]=ans;
}


int main()
{
    string s;
    cin>>s;

    int n=s.size();


    cout<<getvalue(s,0,n-1,true)<<endl<<getvalue_memoization(s,0,n-1,true);
    

}