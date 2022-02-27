#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
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
#endif


    int n,m;
    cin>>n>>m;

    v.resize(n+1+m);
    vis.resize(n+1+m,false);
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        if(a==0)
            res++;
        for(int j=0;j<a;j++)
        {
            int b;
            cin>>b;
            v[i].push_back(b+n);
            v[b+n].push_back(i);
        }
    }
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        if(v[i].empty())
            continue;
        if(!vis[i])
        {
            if(flag)
            {
                flag=!flag;
                res--;
            }
            dfs(i);
            res++;
        }
    }
    cout<<res;






    return 0;
}