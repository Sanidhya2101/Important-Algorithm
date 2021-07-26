#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

void generateparenthesis(int o,int c,string out)
{
    if(o>c)
    return;

    if(o==0 && c==0)
    {
        cout<<out<<"\n";
        return;
    }

    if(o!=0)
    generateparenthesis(o-1,c,out+"(");

    if(c!=0)
    generateparenthesis(o,c-1,out+")");
}

int main()
{
    int n;
    cin>>n;

    string out;

    generateparenthesis(n,n,out);
}