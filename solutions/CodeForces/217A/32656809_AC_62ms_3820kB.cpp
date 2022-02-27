#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
map<int,vector<int>>v;
map<int,bool>vis;
int n;

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

    int res=0;
    int a,b;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        b*=-1;
        vis[a]= false;
        vis[b]=false;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(auto k:v)
    {
        if(!vis[k.first])
        {
            dfs(k.first);
            res++;
        }
    }

    cout<<res-1;


    return 0;
}
