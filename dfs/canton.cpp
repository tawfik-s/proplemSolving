//https://codeforces.com/gym/102944/problem/C
// Author : tawfik shalash
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
#include<bits/stdc++.h>
//cpp 11
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
#define fast     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
int n,m;
vector<string>v;
vector<vector<int>>vis;

int dfs(int x, int y)
{
    if(x==n||x<0||y==m||y<0||vis[x][y]==0)
    {
        return 0;
    }
    if(vis[x][y]==1)
    {
        return 1;
    }
    if(v[x][y]=='S') {
        vis[x][y]=1;
        vis[x][y]=dfs(x+1,y);
        return vis[x][y];
    }
    if(v[x][y]=='N') {
        vis[x][y]=1;
        vis[x][y]=dfs(x-1,y);
        return vis[x][y];
    }
    if(v[x][y]=='E') {
        vis[x][y]=1;
        vis[x][y]=dfs(x,y+1);
        return vis[x][y];
    }
    if(v[x][y]=='W') {
        vis[x][y]=1;
        vis[x][y]=dfs(x,y-1);
        return vis[x][y];
    }
}


int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif


cin>>n>>m;
v.resize(n);
vis.resize(n,vector<int>(m,-1));
for(int i=0;i<n;i++) {
    cin>>v[i];
}
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++) {
        if (vis[i][j]==-1)
        {
            dfs(i,j);
        }
    }
}
int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) {
           if(vis[i][j]==1)
               count++;
        }
    }

    cout<<count;







    return 0;



}