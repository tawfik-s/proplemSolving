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




    ll n,k;
    cin>>n>>k;
    vector<ll>v;
    v.resize(n+1);
    v[0]=0;
    for(ll i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    for(ll i=1;i<=n;i++)
    {
        v[i]+=v[i-1];
    }

    ll min=0;
    ll mm=(v[0+k]-v[0]);
    for(ll i=0;i<=n-k;i++)
    {
        ll jj=(v[i+k]-v[i]);
       // cout<<jj<<endl;
        if(jj<mm)
        {
            mm=jj;
            min=i;
        }
    }
    cout<<min+1;




    return 0;
}