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

unsigned int factorial(unsigned int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif


ll n,m;
cin>>n>>m;
vector<ll>v(n);
for(ll i=0;i<n;i++)
{
    cin>>v[i];
    v[i];
}
sort(v.begin(),v.end());
ll sum=0;
for(ll i=0;i<n-2;i++)
{
    ll x=upper_bound(v.begin(),v.end(),v[i]+m)-(v.begin()+i);

     x-=2;
     sum+=(x*(x+1))/2;
}
cout<<sum;

    return 0;
}