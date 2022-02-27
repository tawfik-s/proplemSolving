
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
ll MOD=1e9+7;
int Max=1e9,q;

int n,t,ans;
vector <int> adj[222];
int dis[222];

void bfs(){
    queue<int> q;
    dis[1]=1;
    q.push(1);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        ans=max(ans,dis[u]);
        for(int v : adj[u]){
            if(!dis[v]){
                dis[v]=dis[u]+1;
                q.push(v);
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
    string a,b,cc;
    map <string, int> mp;
    mp["polycarp"]=1;
    n=1;
    cin>>t;
    while(t--)
    {
        cin>>a>>cc>>b;
        for(int i=0;i<a.length();i++)
        {
            a[i]= tolower(a[i]);
        }
        for(int i=0;i<b.length();i++)
        {
            b[i]= tolower(b[i]);
        }
        if(!mp[a])
            mp[a]=++n;
        
        if(!mp[b])
            mp[b]=++n;
        adj[mp[a]].push_back(mp[b]);
        adj[mp[b]].push_back(mp[a]);
    }
    bfs();
    cout<<ans<<endl;

    return 0;
}
