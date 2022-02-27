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
int n,m;

vector<vector<ii>>adjList;

void dijksta(int s,int sc) {
   vector<ll> dist(n, INF);
    vi par(n,-1);
    dist[s]=0;
    priority_queue<ii,vector<ii>,greater<ii>>pq;
    pq.push({0,s});
    while(!pq.empty())
    {
        ii front=pq.top();
        pq.pop();
        if(front.second==sc&&par[sc]!=-1)
        {

            int i=sc;
            vector<int>res;
            while(par[i]!=-1)
            {
                res.push_back(i+1);
                i=par[i];
            }

            reverse(res.begin(),res.end());
            cout<<1<<" ";
            for(auto kk:res)
            {
                cout<<kk<<" ";
            }
            return;
        }
        int d=front.first,u=front.second;
        if(d>dist[u])continue;
        for(auto v:adjList[u])
        {
            if(dist[u]+v.second<dist[v.first])
            {
                dist[v.first]=dist[u]+v.second;
                pq.push({dist[v.first],v.first});
                par[v.first]=u;
            }
        }
    }
    cout<<-1;

}
int main() {

    fast
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
        adjList.clear();
        cin>>n>>m;
        adjList.resize(n);
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            adjList[--a].push_back({--b,c});
            adjList[b].push_back({a,c});
        }

        dijksta(0,n-1) ;




    return 0;
}


