#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>t;
vector<vector<pair<int,int>>>adj;
vector<ll>dist;
void dijkstra()
{
    priority_queue<pair<ll,pair<int,int>>,vector<pair<ll,pair<int,int>>>,greater<pair<ll,pair<int,int>>>>pq;
    pq.push({0,{0,-1}});
    dist[0]=0;
    while(!pq.empty())
    {
        ll costO=pq.top().first;
        int floor=pq.top().second.first;
        int elv=pq.top().second.second;
        pq.pop();
        for(auto x:adj[floor])
        {
            ll cost=0;
            if(elv!=-1&&x.second!=elv)
                cost+=60;
            if(elv!=-1)
                cost+=t[x.second]*abs(x.first-floor);
            else
                cost+=t[x.second]*abs(x.first-floor);
            cost+=costO;
            if(cost<dist[x.first])
            {
                dist[x.first]=cost;
                pq.push({cost,{x.first,x.second}});
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
    int n,m;
    while(cin>>n>>m)
    {
        adj.clear();
        dist.clear();
        t.clear();
        t.resize(n);
        adj.resize(110);
        dist.resize(110, 1e12);
        for (int i = 0; i < n; i++) {
            cin >> t[i];
        }
        cin.ignore();
        for (int z = 0; z < n; z++) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            int floor;
            vector<int> v;
            while (ss >> floor) {
                v.push_back(floor);
            }
            for (int i = 0; i < v.size(); i++) {
                for (int j = i+1; j < v.size(); j++) {
                    if (i == j)
                        continue;
                    adj[v[i]].push_back({v[j], z});
                    adj[v[j]].push_back({v[i], z});
                }
            }
        }
        dijkstra();
        if(dist[m]==1e12)
            cout<<"IMPOSSIBLE"<<endl;
        else
            cout<<dist[m]<<endl;

    }

    return 0;
}


