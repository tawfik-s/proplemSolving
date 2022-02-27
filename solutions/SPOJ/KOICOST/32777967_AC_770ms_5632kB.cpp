#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,m;
vector<int>par,sz;
vector<pair<int,pair<int,int>>>edges;
ll cnt=0;

int findParent(int u)
{
    if(u==par[u]) return u;
    return par[u]= findParent(par[u]);
}
ll mood=1e9;
void join(int a,int b)
{
    a= findParent(a);
    b= findParent(b);
    if(a!=b)
    {
        if(sz[a]>sz[b])
        {
            swap(a,b);
        }
        cnt=((cnt+(ll)sz[a]*sz[b])%mood);
        sz[b]+=sz[a];
        par[a]=b;
    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    cin>>n>>m;
    par.resize(n,0);
    sz.resize(n,1);
    iota(par.begin(),par.end(),0);
    for(int i=0;i<m;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        --u;--v;
        edges.push_back({c,{u,v}});
    }
    sort(edges.begin(),edges.end(),greater<>());
    ll ans=0;
    cnt=0;
    for(int i=0;i<m;i++)
    {
      int u=edges[i].second.first;
      int v=edges[i].second.second;
      int c=edges[i].first;
      join(u,v);
      ans=(ans+(cnt*c)%mood)%mood;
    }
    cout<<ans;





    return 0;
}
