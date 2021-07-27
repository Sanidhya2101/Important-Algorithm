#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int



bool issafe(vector<vector<int>> &v,int row,int col)
{
    for(int i=0;i<col;i++)
    {
        if(v[row][i])
        return false;
    }

    for(int i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(v[i][j])
        return false;
    }

    for(int i=row,j=col;j>=0 && i<v.size();i++,j--)
    {
        if(v[i][j])
        return false;
    }

    return true;
}

bool solveQUtil(vector<vector<int>> &v,int col,vector<vector<string>> &s)
{
    if(col==v.size())
    {
        vector<string> p;

        for(int i=0;i<v.size();i++)
        {
            string q;
            for(int j=0;j<v.size();j++)
            {
                if(v[i][j]==0)
                q+='0';
                else
                q+='Q';
            }
            p.push_back(q);
        }

        s.push_back(p);

        return true;
    }

    bool res=false;
    for(int i=0;i<v.size();i++)
    {
        if(issafe(v,i,col))
        {
            v[i][col]=1;

            res|=solveQUtil(v,col+1,s);

            v[i][col]=0;
        }

    }

    return res;
}


int main()
{
    int n;
    cin>>n;

    vector<vector<int>> v(n,vector<int>(n,0));

    vector<vector<string>> s;

    if(!solveQUtil(v,0,s))
    cout<<"NO solution";


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<s[i][j]<<"\n";
        }
        cout<<"\n";
    }



}