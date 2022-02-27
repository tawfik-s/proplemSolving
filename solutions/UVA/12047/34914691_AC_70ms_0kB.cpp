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
    while(T--)
    {
        int n,m,s,t,p;
        cin>>n>>m>>s>>t>>p;
        s--;
        t--;
        vector<vector<pair<int,int>>>adjlist(n);
        vector<vector<pair<int,int>>>adjlist2(n);
        vector<ll>dist(n,1e9);
        vector<ll>dist2(n,1e9);
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            a--;
            b--;
            adjlist[a].push_back({b,c});
            adjlist2[b].push_back({a,c});
        }
        dijkstra(s,dist,adjlist);
        dijkstra(t,dist2,adjlist2);

        int r=-1;
        for(int i=0;i<n;i++)
        {
            for(auto edge:adjlist[i])
            {
                if(dist[i]+edge.second+dist2[edge.first]<=p)
                {
                    r=max(r,edge.second);
                }
            }
        }
        cout<<r<<endl;

    }


    return 0;
}


