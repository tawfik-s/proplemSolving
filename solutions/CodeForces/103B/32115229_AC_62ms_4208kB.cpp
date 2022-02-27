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
const int MAX=1000+2;
vector<vector<int>>adj;
vector<bool>visited(10000+2,0);
int vid=1;

void dfs(int node)
{
    visited[node]=true;
    for(auto k:adj[node])
    {
        if(visited[k]!=true)
            dfs(k);
    }
}
bool connected(int node)
{
    visited[node]=true;
    for(auto k:adj[node])
    {
        if(visited[k]!=true)
            dfs(k);
    }

    for(int i=1;i<=n;i++)
    {
        if(visited[i]==false)
            return false;

    }
    return true;

}

int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif




    cin>>n>>m;
    adj.resize(n+1);
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

//    displayadjList();

    int count=0;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            dfs(i);
            count++;
        }
    }

    if(n==m&&count==1)
        cout<<"FHTAGN!";
    else
        cout<<"NO";







    return 0;
}
