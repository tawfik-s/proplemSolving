#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int n,m;
vector<vector<int>>v;
vector<bool>vis;

void dfs(int i)
{
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
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    v.resize(n+1);
    vis.resize(n+1,false);

    for(int i=0;i<n;i++)
    {
        int b;
        cin>>b;
        v[i+1].push_back(b);
        v[b].push_back(i+1);
    }

    int count=0;

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
            count++;
        }
    }

   cout<<count;




    return 0;
}