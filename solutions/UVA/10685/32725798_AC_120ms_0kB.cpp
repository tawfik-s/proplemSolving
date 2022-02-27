#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int n,m,co;
vector<vector<int>>v;
vector<bool>vis;

void dfs(int i)
{
    co++;
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
   while(true) {
        cin >> n >> m;
       v.clear();
       vis.clear();
       if (n == 0 && m == 0)
           return 0;
        co = 0;
        v.resize(n + 1);
        vis.resize(n + 1, false);
        map<string, int> mp;
        string k;
        for (int i = 0; i < n; i++) {
            cin >> k;
            mp[k] = i + 1;
        }

        for (int i = 0; i < m; i++) {
            string a, b;
            cin >> a >> b;
            v[mp[a]].push_back(mp[b]);
            v[mp[b]].push_back(mp[a]);
        }

        int res = 0;
        for (int i = 1; i <= n; i++) {
            co = 0;
            if (!vis[i]) {
                dfs(i);
                res = max(co, res);
            }
        }

        cout << res << endl;
    }




    return 0;
}