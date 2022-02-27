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
typedef pair<ll,ll> ii;
const ll INF=(ll)1e14;
#define fast     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"
int n,m,q;



ii dijksta(int s,vector<vector<ii>>&adjList) {
   vector<ll> dist(n, INF);
    dist[s]=0;
    priority_queue<ii,vector<ii>,greater<ii>>pq;
    pq.push({0,s});
    while(!pq.empty())
    {
        ii front=pq.top();
        pq.pop();
        int d=front.first,u=front.second;
        if(d!=dist[u])continue;
        for(auto v:adjList[u])
        {
            if(dist[u]+v.second<dist[v.first])
            {
                dist[v.first]=dist[u]+v.second;
                pq.push({dist[v.first],v.first});
            }
        }
    }
   ll mx=0;
    for(int i=0;i<n;i++)
    {
        if(dist[i]<INF)
            mx=max(dist[i],mx);
    }
    int cnt= count(dist.begin(),dist.end(),mx);
    return {mx,cnt};

}
int main() {

    fast
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
        vector<vector<ii>>adjList;
        adjList.clear();
        cin>>n>>m>>q;
        adjList.resize(n);
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            adjList[a].push_back({b,c});
            adjList[b].push_back({a,c});
        }
         while (q--)
        {
            int a;
            cin>>a;
            ii ans=dijksta(a,adjList);
            cout<<ans.first<<" "<<ans.second<<endl;
        }





    return 0;
}


