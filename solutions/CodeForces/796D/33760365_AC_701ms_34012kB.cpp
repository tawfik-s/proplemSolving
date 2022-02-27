
/*
author: tawfik shalash
─▄█▄─█▀█▀█─▄█▄
▀▀████▄█▄████▀▀
─────▀█▀█▀

*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> ii;

const ll INF = 1e14;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl "\n"
ll M = 1e9 + 7;
ll OO = 1e9;
ll MOD = 1e9 + 7;
int Max = 1e9, q;



int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n,k,d;
    vector<int>policeStation;
    vector<vector<int>>adj;
    vector<int>vis;
    vector<int>vis2;
    unordered_set<int>res;
    cin >> n >> k >> d;
    adj.resize(n+1);
    vis.resize(n+1,0);
    vis2.resize(n+1,0);

    policeStation.resize(k);
    queue<pair<int,int>>qu; //node and distance;
    for (int i = 0; i < k; i++){
        int x;
        cin>>x;
        policeStation[i]=x;
        vis[x]=1;
        qu.push({x,0});
    }
    int a,b;
    map<pair<int,int>,int>mp;
    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b;
        mp[{min(a,b),max(a,b)}]=i+1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    while(!qu.empty())
    {
        pair<int,int> node=qu.front();
        qu.pop();
        for(auto x:adj[node.first])
        {
            if(vis[x]==0)
            {
                qu.push({x, node.second + 1}); vis[x]=vis[node.first]+1;
                vis2[mp[{min(x,node.first),max(x,node.first)}]]=1;
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        if(vis2[i]==0)
        {
            res.insert(i);
        }
    }


    cout<<res.size()<<endl;
    for(auto x:res)
    {
        cout<<x<<" ";
    }








    return 0;
}

