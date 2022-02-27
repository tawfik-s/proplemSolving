#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int n,m;
vector<vector<pair<int,int>>>v;
vector<bool>in;
vector<bool>vis;
vector<array<int, 3>> ans;
int start;
int mm;
void dfs(int i)
{
    vis[i]=true;
    if(v[i].size()==0) {
        if(start==i) return;
        ans.push_back({start, i, mm});
        return;
    }
        if(!vis[v[i][0].first])
        {
            mm=min(mm,v[i][0].second);
            dfs(v[i][0].first);
        }


}


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m;
    v.resize(n+1);
    vis.resize(n+1,false);
    in.resize(n+1,false);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
            v[a].push_back({b, c});
            in[b]=true;
    }

    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&!in[i])
        {
            start=i;
            mm=INT_MAX;
            dfs(i);
        }
    }

    cout<<ans.size()<<"\n";
    for(auto k:ans)
    {
        cout<<k[0]<<" "<<k[1]<<" "<<k[2]<<"\n";
    }






    return 0;
}