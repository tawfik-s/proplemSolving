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
typedef vector<ll> vi;
typedef set<int> si;
typedef pair<ll,int> ii;
const ll INF=1e14;
#define fast     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"
ll n,m;

vector<vector<pair<int,ll>>> adj;
vector<ll>dist;
vector<ll>ticket;

void dijkstra()
{
    priority_queue<ii,vector<ii>,greater<ii>>pq;
    for(int i=0;i<n;i++)
    {
        dist[i]=ticket[i];
        pq.push({ticket[i],i});
    }
    while(!pq.empty())
    {
        ll w=pq.top().first;
        ll pnode=pq.top().second;
        pq.pop();
        if(w!=dist[pnode])continue;
        for(auto v:adj[pnode])
        {
            ll sw=v.second*2;
            ll sn=v.first;
            if(dist[sn]>dist[pnode]+sw)
            {
                dist[sn]=dist[pnode]+sw;
                pq.push({dist[sn],sn});
            }

        }
    }

}
int main() {

    fast
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    cin>>n>>m;
    dist.resize(n);
    ticket.resize(n);
    adj.resize(n);
    for(int i=0;i<m;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        adj[--a].push_back({--b,c});
        adj[b].push_back({a,c});
    }
    for(int i=0;i<n;i++)
    {
        cin>>ticket[i];
    }
    dijkstra();
    for(int i=0;i<n;i++)
    {
        cout<<dist[i]<<' ';
    }

    return 0;
}


