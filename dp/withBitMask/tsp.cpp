#include <bits/stdc++.h>
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;
typedef long long ll;

const int N = 1e5 + 5, M = 1e3 + 5, MOD = 1e9 + 7, OO = 0x3f3f3f3f;
const ll LOO = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-8;

int n, m;
vector<vector<int>> dis;
vector<vector<int>> mem;

// O(n^2 * 2^n) n=18-20
int solve(int cur, int mask)
{
    if (mask == (1 << n) - 1)
        return 0;
    if (mem[cur][mask] != -1)
        return mem[cur][mask];
    int ret = OO;
    for (int nxt = 0; nxt < n; nxt++)
    {
        if ((mask >> nxt) & 1)
            continue;
        ret = min(ret, dis[cur][nxt] + solve(nxt, mask | (1 << nxt)));
    }
    return mem[cur][mask] = ret;
}

int main()
{
    FIO
            //    freopen("input.txt","rt",stdin);
            //    freopen("output.txt","wt",stdout);
            cin >>
        n >> m;
    dis = vector<vector<int>>(n, vector<int>(n, OO));
    mem = vector<vector<int>>(n, vector<int>(1 << n, -1));
    for (int i = 0; i < n; i++)
        dis[i][i] = 0;
    while (m--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        dis[u][v] = dis[v][u] = min(dis[u][v], c);
    }

    for (int k = 0; k < n; k++)
        for (int u = 0; u < n; u++)
            for (int v = 0; v < n; v++)
                dis[u][v] = min(dis[u][v], dis[u][k] + dis[k][v]);

    int st;
    cin >> st;
    int ans = solve(st, 1 << st);
    if (ans >= OO)
        ans = -1;
    cout << ans << '\n';

    return 0;
}