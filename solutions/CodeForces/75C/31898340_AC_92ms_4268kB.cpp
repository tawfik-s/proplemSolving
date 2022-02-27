// Author : tawfik shalash
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
#include<bits/stdc++.h>

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

vi comDiv(ll a, ll b)
{
    vi v;
    ll n=__gcd(a,b);
    ll result=0;
    for(ll i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            if(n/i==i)
            {
                v.push_back(i);
            }
            else
            {

                    v.push_back(i);
                v.push_back(n/i);
            }
        }
    }

    return v;
}
int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    int a,b;
    cin>>a>>b;

    vi v= comDiv(a,b);
    sort(v.begin(),v.end());
    ll q;
    cin>>q;
    map<pair<ll,ll>,ll>mp;
    while(q--)
    {

        ll l,h;
        cin>>l>>h;
        if(mp[{l,h}]!=0)
        {
            cout<<mp[{l,h}]<<endl;
            continue;
        }

        ll res; res=-1;
        for(auto i:v)
        {
            if(i>=l&&i<=h)
                res=i;
        }
        cout<<res<<endl;
        mp[{l,h}]=res;


    }




    return 0;
}
