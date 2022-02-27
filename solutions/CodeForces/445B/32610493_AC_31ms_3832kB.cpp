#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<vector<int>>v;
vector<bool>vis;
ll maxx=1;
void dfs(int i)
{
    maxx++;
    vis[i]=true;
    for(auto k:v[i])
    {
        if(!vis[k])
        {
            dfs(k);
        }
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif


    int n,m;
    cin>>n>>m;
    v.resize(n+1);
    vis.resize(n+1,false);
    int a,b;
    if(m==0)
    {
        cout<<1;
        return 0;
    }
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    ll res=0;

    for(int i=1;i<n+1;i++)
    {
        if(!vis[i])
        {
            maxx=0;
            vis[i]=true;
            dfs(i);
            res+=maxx-1;
        }
    }

     cout<<(1ll<<res);





    return 0;
}