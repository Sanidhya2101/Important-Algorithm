#include<bits/stdc++.h>
using namespace std;

//AAAAACCCCCAAAAACCCCCCAAAAAGGGTT    ans=2
#define ll long long int
#define ul unsigned long int


int main()
{
    string s;
    cin>>s;

    unordered_map<char,int> mp;
    mp['A']=0;
    mp['C']=1;
    mp['G']=2;
    mp['T']=3;

    int bitmask = (1<<20)-1;
    int cnt=0;
    for(int i=0;i<10;i++)
    {
        cnt=(cnt<<2)|mp[s[i]];
    }

    unordered_map<int,int> map;
    map[cnt]++;

    int ans=0;

    for(int i=10;i<s.size();i++)
    {
        cnt=((cnt<<2)&bitmask)|mp[s[i]];

        if(map.find(cnt)!=map.end() && map[cnt]==1)
        ans++;

        map[cnt]++;
    }

    cout<<ans;

}