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

set<pair<int,int>> ans;

int dist(pair<int,int> x,pair<int,int> y,pair<int,int> p)
{
    return abs((p.second-x.second)*(y.first-x.first)-(p.first-x.first)*(y.second-x.second));
}

int findside(pair<int,int> x,pair<int,int> y,pair<int,int> p)
{
    int val = (p.second-x.second)*(y.first-x.first)-(p.first-x.first)*(y.second-x.second);

    if(val>0)
    return 1;

    if(val<0)
    return -1;

    return 0;
}

void quickhull(vector<pair<int,int>> p,pair<int,int> x,pair<int,int> y,int side)
{
    int j=-1;
    int max_dist=0;

    for(int i=0;i<p.size();i++)
    {
        int tmp = dist(x,y,p[i]);

        if(findside(x,y,p[i])==side && tmp>max_dist)
        {
            j=i;
            max_dist=tmp;
        }
    }

    if(j==-1)
    {   
        ans.insert(x);
        ans.insert(y);
        return;
    }

    quickhull(p,p[j],x,-findside(p[j],x,y));

    quickhull(p,p[j],y,-findside(p[j],y,x));
}

void convexhull(vector<pair<int,int>> p)
{
    int min_x=0;
    int max_x=0;
    int n=p.size();

    for(int i=0;i<n;i++)
    {
        if(p[i].first<p[min_x].first)
        min_x=i;

        if(p[i].first>p[max_x].first)
        max_x=i;
    }

    quickhull(p,p[min_x],p[max_x],1);

    quickhull(p,p[min_x],p[max_x],-1);


    

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

    convexhull(p);

    for(auto x:ans)
    {
        cout<<"{"<<x.first<<","<<x.second<<"}\n";
    }
    
}