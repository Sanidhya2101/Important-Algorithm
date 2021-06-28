#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

char getnextchar(string s,int k)
{
    int start=0;
    int end=s.size()-1;

    char res='#';

    while(start<=end)
    {
        int mid=start+(end-start)/2;

        if(s[mid]==k)
        return s[mid+1];

        else if(s[mid]>k)
        {
            res=s[mid];
            end=mid-1;
        }

        else
        {
            start=mid+1;
        }

    }

    return res;
}

int main()
{
    string s;
    cin>>s;

    char k;
    cin>>k;

    cout<<getnextchar(s,k);
}