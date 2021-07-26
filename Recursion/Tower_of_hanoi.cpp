#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define ul unsigned long int

void tower_of_hanoi(int n,int s,int d,int h,int &cnt)
{
    cnt++;
    if(n==1)
    {
        cout<<"Moving Plate "<<n<<" from "<<s<<" to "<<d<<"\n";
        return;
    }

    tower_of_hanoi(n-1,s,h,d,cnt);

    cout<<"Moving Plate "<<n<<" from "<<s<<" to "<<d<<"\n";

    tower_of_hanoi(n-1,h,d,s,cnt);
}

int main()
{
    int n;
    cin>>n;

    int s=1;
    int h=2;
    int d=3;

    int cnt=0;
     
    tower_of_hanoi(n,s,d,h,cnt);

    cout<<cnt;
}