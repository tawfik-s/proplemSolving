
/*
author: tawfik shalash
─▄█▄─█▀█▀█─▄█▄
▀▀████▄█▄████▀▀
─────▀█▀█▀

*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> ii;

const ll INF = 1e14;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl "\n"
ll M = 1e9 + 7;
ll OO = 1e9;
ll MOD = 1e9 + 7;
int Max = 1e9, q;
int n;
vector<vector<int>>adj;
vector<int>vis;

void dfs(int node)
{
    for(auto j:adj[node])
    {
        if(vis[j]==-1)
        {
            vis[j]=1;
            dfs(j);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while(cin>>n,n)
    {
        adj.clear();
        adj.resize(n+3);
        int j;
        while(cin>>j,j)
        {
            int k;
            while(cin>>k,k)
            {
                adj[j].push_back(k);
            }
        }
        int q;
        cin>>q;
        while(q--)
        {
            int k;
            cin>>k;
            vis=vector<int>(n+3,-1);
            vector<int>res;
             dfs(k);
            for(int i=1;i<=n;i++)
            {
                if(vis[i]==-1)
                {
                    res.push_back(i);
                }
            }
            cout<<res.size();
            for(auto ans:res)
            {
                cout<<" "<<ans;
            }
            cout<<endl;
        }

    }


    return 0;
}

