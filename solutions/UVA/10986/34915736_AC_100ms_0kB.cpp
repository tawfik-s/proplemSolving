#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dijkstra(int start,vector<ll>&dist,vector<vector<pair<int,int>>>&adjlist)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,start});
    dist[start]=0;
    while(!pq.empty())
    {
        auto cur=pq.top();
        pq.pop();
        for(auto x:adjlist[cur.second])
        {
            if(dist[x.first]>cur.first+x.second)
            {
                dist[x.first]=cur.first+x.second;
                pq.push({cur.first+x.second,x.first});
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
    int T;
    cin>>T;
    int kkk=1;
    while(T--)
    {
        cout<<"Case #"<<kkk++<<": ";
        int n,m,s,t;
        cin>>n>>m>>s>>t;
        vector<vector<pair<int,int>>>adjlist(n);
        vector<ll>dist(n,1e9);
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            adjlist[a].push_back({b,c});
            adjlist[b].push_back({a,c});
        }
        dijkstra(s,dist,adjlist);
        if(dist[t]>=1e9)
            cout<<"unreachable"<<endl;
        else
             cout<<dist[t]<<endl;

    }


    return 0;
}


