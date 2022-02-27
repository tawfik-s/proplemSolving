// Author : tawfik shalash
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
#include<bits/stdc++.h>
//cpp 11
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
#define fast     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;



int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

 ll n,a,b,c;
cin>>n>>a>>b>>c;
ll minn=0;
vector<ll>v={a,b,c};
sort(v.begin(),v.end());
c=v[0];
b=v[1];
a=v[2];
for(ll i=0;i<150;i++)
{
    for(ll k=0;k<150;k++)
    {
        for(ll j=0;j<=4000;j++)
        {
            if(a*i+b*k+c*j==n)
            {
                minn=max(minn,i+j+k);
            }
        }
    }
}
cout<<minn;


    return 0;
}