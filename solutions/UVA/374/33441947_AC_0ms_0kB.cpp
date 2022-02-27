#include<bits/stdc++.h>
#define Sakr_ ios_base :: sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0)
#define ll long long int

using namespace std;

/*
by:Ahmed Sakr (sakr_) with AZA ;l

#ifndef ONLINE_JUDGE
   freopen("c.in", "r", stdin);
#endif
*/

ll power(ll b,ll a,ll m)
{
    if(a==0) return 1;
    if(a==1) return b%m;

    if(a%2==0)
    {
        ll x=(power(b,a/2,m))%m;

        return (x%m *x%m)%m;
    }
    else
    {
        ll x=(power(b,a/2,m))%m;

        return ((x%m * x%m)*b%m)%m;
    }


}


int main()
{
    ll b,a,m,t;

    while(cin>>b>>a>>m)
    {

        cout<<power(b,a,m)<<"\n";
    }
}
