#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dijkstra(int start,vector<vector<ll>>&dist,vector<vector<pair<int,int>>>&adjlist)
{
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    pq.push({0, {start,0}});
    dist[start][0]=0;

    while(!pq.empty())
    {
        auto cur=pq.top();
        pq.pop();
        for(auto x:adjlist[cur.second.first])
        {
            if(dist[x.first][!cur.second.second]>cur.first+x.second)
            {
                dist[x.first][!cur.second.second]=cur.first+x.second;
                pq.push({cur.first+x.second, {x.first,!cur.second.second}});
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
    int kkk=1;int n,m;
    while(cin>>n>>m)
    {
        cout<<"Set #"<<kkk++<<endl;

        vector<vector<pair<int,int>>>adjlist(n);
        vector<vector<ll>>dist(n,vector<ll>(2,1e9));
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            adjlist[a].push_back({b,c});
            adjlist[b].push_back({a,c});
        }
        dijkstra(0,dist,adjlist);
        if(dist[n-1][0]>=1e9)
            cout<<"?"<<endl;
        else
            cout<<dist[n-1][0]<<endl;

    }


    return 0;
}

