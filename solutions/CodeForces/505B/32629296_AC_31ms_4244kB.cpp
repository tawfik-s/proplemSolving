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
int res=0;
int j,fin;
vector<vector<pair<int,int>>>adj;
set<pair<int,int>>vis;
set<int>colors;
void dfs(int n,int l)
{
    vis.insert({n, l});
    if(fin==n)
    {
        colors.insert(l);
        return;
    }
    for(auto k:adj[n])
    {
        if(vis.find(k)==vis.end()&&k.second==l)
        {
                dfs(k.first, k.second);
        }

    }
}


int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    int n,m;
    cin>>n>>m;

    adj.resize(n+1);

    int a,b,c;

    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;

        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    int q;
    cin>>q;
    while(q--)
    {
        res=0;
        vis.clear();
        colors.clear();
        cin>>j>>fin;
        for(auto k:adj[j]) {
            if(fin==k.first)
            {
                colors.insert(k.second);
                continue;
            }
            dfs(k.first, k.second);
        }
        cout<<colors.size()<<endl;
    }






    return 0;
}








