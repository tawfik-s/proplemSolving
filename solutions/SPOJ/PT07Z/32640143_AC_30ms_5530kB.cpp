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
typedef vector<int> vi;
typedef set<int> si;
#define fast     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"
int n,m;
bool flag=true;
int bfs(vector<vector<int>>&adj,int i)
{
    queue<int>qu;
    qu.push(i);
    vector<int>vis(n+1,0);
    vis[i]=0;

    while(!qu.empty())
    {
        int node=qu.front();
         qu.pop();
        for(auto k:adj[node])
        {
            if(vis[k]==0)
            {
                qu.push(k);
                vis[k]=vis[node]+1;
            }

        }


    }
    int x=1;

    for(int j=2;j<=n;j++)
    {
        if(vis[j]>vis[x])
        {
            x=j;
        }

    }

    if(flag)
    {
        flag=false;
        return x;

    }
    else
    {
        return vis[x];
    }

}


int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

cin>>n;

vector<vector<int>>adj(n+1);
int a,b;
for(int i=1;i<n;i++)
{
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
}

int x=bfs(adj,1);
int fin=bfs(adj,x);

cout<<fin;




    return 0;
}








