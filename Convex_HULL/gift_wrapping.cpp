#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

/*
8                                        
0 3
1 1
2 2
4 4
0 0
1 2
3 1
3 3
*/


int orientation(pair<int,int> a,pair<int,int> b,pair<int,int> c)
{
    int d=(b.second-a.second)*(c.first-b.first)-(b.first-a.first)*(c.second-b.second);

    if(d==0)
    return 0;

    if(d<0)
    return 1;

    return 2;
}



vector<pair<int,int>> convexhull(vector<pair<int,int>> p)
{
    vector<pair<int,int>> ans;
    int n=p.size();

    int j=0;

    for(int i=0;i<n;i++)
    {
        if(p[j].second>p[i].second)
        j=i;
    }

    int k=j;
    int q;


    do{

        ans.push_back({p[k].first,p[k].second});

        q=(k+1)%n;

        for(int i=0;i<n;i++)
        {
            if(orientation(p[k],p[i],p[q])==2)
            q=i;
        }

        k=q;

    }while(k!=j);

    return ans;
}


int main()
{
    int n;
    cin>>n;

    vector<pair<int,int>> p;

    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;

        p.push_back({x,y});
    }

    for(auto x:convexhull(p))
    cout<<"{"<<x.first<<","<<x.second<<"}\n";
}