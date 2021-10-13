#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

pair<int,int> p0;

int orientation(pair<int,int> a,pair<int,int> b,pair<int,int> c)
{
    int v = (b.second-a.second)*(c.first-b.first)-(b.first-a.first)*(c.second-b.second);

    if(v==0)
    return 0;

    return v>0?1:2;
}

int dist(pair<int,int> a,pair<int,int> b)
{
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

pair<int,int> nexttotop(stack<pair<int,int>> &s)
{
    pair<int,int> p=s.top();
    s.pop();
    pair<int,int> q=s.top();
    s.push(p);
    return q;
}


int compare(const void *vp1,const void *vp2)
{
    pair<int,int> *p1 = (pair<int,int>*)vp1;
    pair<int,int> *p2 = (pair<int,int>*)vp2;

    int o=orientation(p0,*p1,*p2);
    if(o==0)
    return (dist(p0,*p2)>=dist(p0,*p1))?-1:1;

    
    return (o == 2)? -1: 1;
}


void convexhull(vector<pair<int,int>> p)
{
    int y_min=p[0].second;
    int min=0;

    for(int i=1;i<p.size();i++)
    {
        int y=p[i].second;
        if(y<y_min || (y_min==y && p[i].first<p[min].first))
        {
            y_min=p[i].second;
            min=i;
        }
    }

    swap(p[0],p[min]);

    p0=p[0];

    qsort(&p[1],p.size()-1,sizeof(p),compare);

    int j=1;

    for(int i=1;i<p.size();i++)
    {
        while(i<p.size()-1 && orientation(p0,p[i],p[i+1])==0)
        i++;

        p[j]=p[i];
        j++;

    }


    stack<pair<int,int>> s;

    s.push(p[0]);
    s.push(p[1]);
    s.push(p[2]);

    for(int i=3;i<p.size();i++)
    {
        while(s.size()>1 && orientation(nexttotop(s),s.top(),p[i])!=2)
        s.pop();

        s.push(p[i]);
    }

    while(!s.empty())
    {
        cout<<"{"<<s.top().first<<","<<s.top().second<<"}\n";
        s.pop();
    }
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
}