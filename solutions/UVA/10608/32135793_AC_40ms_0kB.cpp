#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll N=1e6+5;

vector<vector<int>>v;
vector<int>vis;
ll dfs(int node,int k)
{

    vis[node]=k;
    ll sz=1;

    for(auto x:v[node])
    {
        if(vis[x]!=k)
        {
            sz+=dfs(x,k);

        }
    }
    return sz;
}


int main()
{

    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m,k=1;
        cin>>n>>m;
        vis.resize(n+1,0);
        v.resize(n+1);

        for(int i=0;i<m;i++)
        {
            int a,b;

            cin>>a>>b;

            v[a].push_back(b);
            v[b].push_back(a);
        }

        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]!=k)
            {
                ans=max(ans,dfs(i,k));
            }
        }
        cout<<ans<<"\n";
        v.clear();
        vis.clear();
    }

}