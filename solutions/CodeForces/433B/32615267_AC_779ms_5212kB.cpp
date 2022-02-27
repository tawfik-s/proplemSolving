#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<vector<int>>v;
vector<bool>vis;
void dfs(int i)
{
    vis[i]=true;
    for(auto k:v[i])
    {
        if(!vis[k])
        {
            dfs(k);
        }
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif




    ll n;
    cin>>n;
    vector<ll>v,vs;
    v.resize(n+1);
    vs.resize(n+1);
    v[0]=0;
    vs[0]=0;
    for(ll i=1;i<=n;i++)
    {
        cin>>v[i];
        vs[i]=v[i];
    }
    sort(vs.begin(),vs.end());
    for(ll i=1;i<=n;i++)
    {
        v[i]+=v[i-1];
        vs[i]+=vs[i-1];
    }

    ll t;
    cin>>t;
    ll a,b,c;
    while(t--) {
        cin >> a >> b >> c;
        if (a == 1) {
            cout<<v[c]-v[b-1]<<"\n";

        } else
        {
            cout<<vs[c]-vs[b-1]<<"\n";
        }

    }





    return 0;
}