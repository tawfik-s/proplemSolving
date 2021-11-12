#include <bits/stdc++.h>
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;
typedef long long ll;

const int N = 3e4 + 5, M = 175, Q = 2e5 + 5, MOD = 1e9 + 7, OO = 0x3f3f3f3f;
const ll LOO = 0x3f3f3f3f3f3f3f3f;
const long double ESP = 1e-8;

int main()
{
    FIO
        //    freopen("input.txt","rt",stdin);
        //    freopen("output.txt","wt",stdout);

        int n,
        m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> dis(n, vector<ll>(n, LOO));
    vector<vector<int>> nxt(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        dis[i][i] = 0;
        nxt[i][i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        --u, --v;
        dis[u][v] = min(dis[u][v], c);
        nxt[u][v] = v;
        dis[v][u] = min(dis[v][u], c);
        nxt[v][u] = u;
    }

    for (int k = 0; k < n; k++)
    {
        for (int u = 0; u < n; u++)
        {
            for (int v = 0; v < n; v++)
            {
                if (dis[u][v] > dis[u][k] + dis[k][v])
                {
                    dis[u][v] = dis[u][k] + dis[k][v];
                    nxt[u][v] = nxt[u][k];
                }
            }
        }
    }
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        if (dis[u][v] >= LOO)
            cout << "-1\n";
        else
        {
            bool neg = 0;
            cout << u + 1 << ' ';
            while (u != v)
            {
                u = nxt[u][v];
                if (u != v && dis[u][u] < 0)
                    neg = 1;
                cout << u + 1 << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
