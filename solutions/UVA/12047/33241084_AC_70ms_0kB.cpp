
/*
author: tawfik shalash
　　██░▀██████████████▀░██
　　█▌▒▒░████████████░▒▒▐█
　　█░▒▒▒░██████████░▒▒▒░█
　　▌░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▐
　　░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░
　 ███▀▀▀██▄▒▒▒▒▒▒▒▄██▀▀▀██
　 ██░░░▐█░▀█▒▒▒▒▒█▀░█▌░░░█
　 ▐▌░░░▐▄▌░▐▌▒▒▒▐▌░▐▄▌░░▐▌
　　█░░░▐█▌░░▌▒▒▒▐░░▐█▌░░█
　　▒▀▄▄▄█▄▄▄▌░▄░▐▄▄▄█▄▄▀▒
　　░░░░░░░░░░└┴┘░░░░░░░░░
　　██▄▄░░░░░░░░░░░░░░▄▄██
　　████████▒▒▒▒▒▒████████
　　█▀░░███▒▒░░▒░░▒▀██████
　　█▒░███▒▒╖░░╥░░╓▒▐█████
　　█▒░▀▀▀░░║░░║░░║░░█████
　　██▄▄▄▄▀▀┴┴╚╧╧╝╧╧╝┴┴███
　　██████████████████████
     عك وليس كله كويس
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<ll, int> ii;
const ll INF = 1e14;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl "\n"
ll M = 1e9 + 7;
ll OO = 1e9;

int n, m, pp;
vector<vector<pair<int, int>>>adj;
vector<vector<pair<int, int>>>radj;
vector<int>dist,dist1;


void dijkstra(int src){
    dist=vector<int>(n,OO);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
    dist[src]=0;
    q.push({0,src});
    while(!q.empty()){
        int u=q.top().second;
        int c=q.top().first;
        q.pop();
        if(c!=dist[u])
            continue;
        for(auto p : adj[u]){
            int v=p.second;
            int vc=p.first;
            if(dist[v]>dist[u]+vc){
                dist[v]=dist[u]+vc;
                q.push({dist[v],v});
            }
        }
    }
}
void rdijkstra(int src){
    dist1=vector<int>(n,OO);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
    dist1[src]=0;
    q.push({0,src});
    while(!q.empty()){
        int u=q.top().second;
        int c=q.top().first;
        q.pop();
        if(c!=dist1[u])
            continue;
        for(auto p : radj[u]){
            int v=p.second;
            int vc=p.first;
            if(dist1[v]>dist1[u]+vc){
                dist1[v]=dist1[u]+vc;
                q.push({dist1[v],v});
            }
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    int T;
    cin >> T;
    while (T--)
    {
        dist.clear();dist1.clear();
        adj.clear();
        radj.clear();
        int src, tar;
        cin >> n >> m>>src>>tar>>pp;
        adj.resize(n);
        radj.resize(n);
        for (int i = 0; i < m; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            adj[--u].push_back({ c,--v });
            radj[v].push_back({c,u});
        }
         dijkstra(--src);  //from src
         rdijkstra(--tar);  //from dest  to see the biggest value from both and compare
         
         int myans=-1;

         for(int u=0;u<n;u++)
         {
             for(auto edge:adj[u])
             {
                 if((dist[u]+dist1[edge.second]+edge.first)<=pp) //check if its smaller than pp
                 {
                        myans=max(myans,edge.first);          
                 }
             }
         }
         cout<<myans<<endl;


    }




    return 0;
}
