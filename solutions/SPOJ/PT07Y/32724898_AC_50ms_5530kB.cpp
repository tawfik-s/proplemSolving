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
    cin>>n>>m;
    v.resize(n+1);
    vis.resize(n+1,false);

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
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

    if(count==1&&m==n-1)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }





    return 0;
}