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
vector<vector<int>> adj, anc;
vector<int> depth;

int Log(int x)
{
    return 31 - __builtin_clz(x);
}

void DFS(int u, int p)
{
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        depth[v] = depth[u] + 1;
        anc[v][0] = u;
        for (int i = 1; i < m; i++)
            anc[v][i] = anc[anc[v][i - 1]][i - 1];
        DFS(v, u);
    }
}

int k_anc(int u, int k)
{
    for (int i = 0; i < m; i++)
        if (k & (1 << i))
            u = anc[u][i];
    return u;
}

int LCA(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    int k = depth[u] - depth[v];
    u = k_anc(u, k);

    if (u == v)
        return u;
    for (int i = m - 1; i >= 0; i--)
    {
        if (anc[u][i] != anc[v][i])
        {
            u = anc[u][i];
            v = anc[v][i];
        }
    }
    return anc[u][0];
}

int main()
{
    FIO
            //    freopen("input.txt","rt",stdin);
            //    freopen("output.txt","wt",stdout);

            cin >>
        n;
    m = Log(n) + 1;
    adj.resize(n);
    depth.resize(n);
    anc = vector<vector<int>>(n, vector<int>(m));
    // Take the tree
    int root = 0;
    anc[root][0] = root;
    depth[root] = 0;
    DFS(root, -1);

    return 0;
}