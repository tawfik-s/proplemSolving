#include <bits/stdc++.h>
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;
typedef long long ll;

const int N = 3e4 + 5, M = 175, Q = 2e5 + 5, MOD = 1e9 + 7, OO = 0x3f3f3f3f;
const long double ESP = 1e-8;

#define cost first
#define from second.first
#define to second.second

int n, m;
vector<pair<int, pair<int, int>>> edges;

pair<bool, ll> bellman(int src, int tar)
{

    vector<int> dis(n, OO);
    dis[src] = 0;
    bool hasCycle = 0;
    for (int i = 1; i <= n; i++)
    {
        bool isUpdated = 0;
        for (auto e : edges)
        {
            if (dis[e.to] > dis[e.from] + e.cost)
            {
                dis[e.to] = dis[e.from] + e.cost;
                isUpdated = 1;
            }
        }
        if (isUpdated == 0)
            break;
        else if (i == n)
            hasCycle = 1;
    }
    return {hasCycle, dis[tar]};

    // To check the nodes affected by negative cycle
    /*
    vector<bool>hasCycle(n,0);
    for(int i=1; i<=n-1; i++){
        for(auto e : edges){
            if(dis[e.to]>dis[e.from]+e.cost){
                dis[e.to]=dis[e.from]+e.cost;
                hasCycle[e.to]=1;
            }
            if(hasCycle[e.from])
                hasCycle[e.to]=1;
        }
    }
    */
}

int main()
{
    FIO
            //    freopen("input.txt","rt",stdin);
            //    freopen("output.txt","wt",stdout);
            cin >>
        n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back({c, {--u, --v}});
    }
    int src, tar;
    cin >> src >> tar;
    pair<bool, int> ans = bellman(--src, --tar);
    if (ans.first)
        cout << "Has negative cycle\n";
    else
        cout << ans.second << '\n';
    return 0;
}