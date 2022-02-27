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
// Recursive function to return gcd of a and b
ll gcd2(ll a, ll b)
{
    
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;
    
    if (a > b)
        return gcd2(a-b, b);
    return gcd2(a, b-a);
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);

}

int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    ll n,m;
    cin>>n>>m;
    vll a(n);
    vll b(m);

    for(ll i=0;i<n;i++)
        cin>>a[i];
    for(ll j=0;j<m;j++)
        cin>>b[j];
    ll t=0;
    for(int i=1;i<n;i++)
        t=gcd((abs(a[i]-a[i-1])),t);    // calculate the gcd of a
    for(int i=0;i<m;i++)
        cout<<gcd((a[0]+b[i]),t)<<" ";      //calc the gcd of a gcd and each element in b and print


    return 0;
}
