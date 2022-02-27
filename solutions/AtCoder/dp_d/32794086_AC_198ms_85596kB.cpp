#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,m;

vector<pair<ll,ll>>v;
ll vis[105][100005];
ll solve(ll remainder,ll index)
{
    if(index==n)
        return 0;

    ll take=0;
    ll leave=0;
    if(vis[index][remainder]!=-1)
        return vis[index][remainder];


    if(remainder-v[index].first>=0)
        take=solve(remainder-v[index].first,index+1)+v[index].second;

        leave=solve(remainder,index+1);

    return vis[index][remainder]=max(take,leave);
}




int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif


    cin>>n>>m;
    v.resize(n);
    memset(vis,-1,sizeof vis);
    for(int i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        v[i]={a,b};
    }
    cout<<solve(m,0);


    return 0;
}