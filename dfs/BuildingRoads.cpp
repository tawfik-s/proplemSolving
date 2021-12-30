/*
author: tawfik shalash
─▄█▄─█▀█▀█─▄█▄
▀▀████▄█▄████▀▀
─────▀█▀█▀
 
*/
 
 // problem link:https://cses.fi/problemset/task/1666
 
#include <bits/stdc++.h>
 
using namespace std;
 
 
//tawfik shalash
 
/*
بسم الله الرحمن الرحيم
 
*/
typedef long long ll;
 
int n,m;
 
vector<int>vis;
vector<vector<int>>adj;
int comp=0;
int dfs(int i)
{
    vis[i]=comp;
    for(int c:adj[i])
    {
        if(vis[c]==-1)
        {
            vis[c]=comp;
            dfs(c);
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
 
    cin>>n>>m;
    vis.resize(n+1,-1);
    adj.resize(n+1);
 
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>zozo;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==-1)
        {
            comp++;
            dfs(i);
            zozo.push_back(i);
        }
    }
    cout<<zozo.size()-1<<endl;
    for(int i=1;i<zozo.size();i++)
    {
        cout<<zozo[i-1]<<" "<<zozo[i]<<endl;
    }
 
 
 
 
 
 
 
    return 0;
 
}