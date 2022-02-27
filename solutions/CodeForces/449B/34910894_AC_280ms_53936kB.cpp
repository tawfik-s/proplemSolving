#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
vector<vector<pair<int,ll>>>adj;
vector<pair<int,ll>>vp;
struct edge{
    int from,to;
    ll cost;
};

void sssp(int start,vector<ll>&dis)
{
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
    pq.push({0,start});
    dis[start]=0;
    while(!pq.empty())
    {
        auto cur=pq.top();
        pq.pop();
        if(cur.first>dis[cur.second])continue;
        for(auto x:adj[cur.second])
        {
           if(cur.first+x.second<dis[x.first])
           {
               dis[x.first]=cur.first+x.second;
               pq.push({dis[x.first],x.first});
           }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> n >> m >> k;
    vector<ll>dis;
    vector<int>reach((int)9e5,0);
    adj.resize(n+1 );
    dis.resize(n +1, 1e12);
    vp.resize(k);
    vector<edge>edgeList(m*3);
    int q=0;
    for (int i = 0; i < m; i++) {
        int a, b;ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        edgeList[q++]={a,b,c};
        edgeList[q++]={b,a,c};
    }
    for (int i = 0; i < k; i++)
    {
        ll a,b;
        cin>>a>>b;

        vp[i]={a,b};
        adj[1].push_back({a,b});
        adj[a].push_back({1,b});
    }
    sssp(1,dis);

    for(int i = 0 ; i<q; i++){
        edge e = edgeList[i];
        if(dis[e.from]+e.cost==dis[e.to]){
            reach[e.to] = 1;
        }
    }
    int rem = 0;
    for(int i = 0 ; i<k ; i++){
        edge e = {1,vp[i].first,vp[i].second};
        if(reach[e.to] || dis[e.from]+e.cost!=dis[e.to]){
            rem++;
        }else{
            reach[e.to] = 1;
        }
    }
    cout << rem << endl;

    return 0;
}
