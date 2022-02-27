#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dijkstra(int start,vector<vector<ll>>&dist,vector<vector<pair<int,pair<int,int>>>>&adjlist)
{
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    pq.push({0, {start,50}});
    for(int i = 0; i < 26; i++)
    {
        dist[start][i] = 0;
    }
    while(!pq.empty())
    {
        auto cur=pq.top();
        pq.pop();
        for(auto x:adjlist[cur.second.first])
        {
            if(dist[x.first][x.second.second]>cur.first+x.second.first&&x.second.second!=cur.second.second )
            {
                dist[x.first][x.second.second]=cur.first+x.second.first;
                pq.push({cur.first+x.second.first, {x.first,x.second.second}});
            }
        }
    }

}

int main() {
   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    while(cin>>n&&n)
    {
        vector<int>arr(5000,0);
        map<string,int>mp;
        int x=1;
        string s,e;
        cin>>s>>e;
        mp[s]=x++;
        mp[e]=x++;
        vector<vector<pair<int,pair<int,int>>>>adjlist(4009);

        vector<vector<ll>>dist(4009,vector<ll>(26,1e9));
        for(int i=0;i<n;i++)
        {
            string a,b,c;
            cin>>a>>b>>c;
            if(mp[a]==0)
            {
                mp[a]=x++;
            }
            if(mp[b]==0)
            {
                mp[b]=x++;
            }
            int u=mp[a];
            int v=mp[b];
            adjlist[u].push_back({v, {c.length(),c[0]-'a'}});
            adjlist[v].push_back({u, {c.length(),c[0]-'a'}});
        }
        dijkstra(1,dist,adjlist);
        ll ans=(int)1e9;
        for(int i = 0; i < 26; i++)
        {
            ans = min(ans, dist[2][i]);
        }
        if(ans>=1e9)
            cout<<"impossivel"<<endl;
        else
             cout<<ans<<endl;

    }


    return 0;
}


