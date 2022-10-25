#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;

int n, m;

int vis[N], vid, lowlink[N], dfst[N], tim, cmpId[N], componentNum, stck[N], stcksz;
vector<int> adj[N];

void sccdfs(int u)
{
    cmpId[u] = -1;
    dfst[u] = lowlink[u] = tim++;
    stck[stcksz++] = u;
    vis[u] = vid;
    for (int j = 0; j < adj[u].size(); j++)
    {
        int v = adj[u][j];
        if (vis[v] != vid)
        { // dfs edge
            sccdfs(v);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        }
        else if (cmpId[v] == -1)
        { // back edge
            lowlink[u] = min(lowlink[u], lowlink[v]);
        }
    }

    if (lowlink[u] == dfst[u])
    {
        do
        {
            cmpId[stck[--stcksz]] = componentNum;
        } while (stck[stcksz] != u);
        componentNum++;
    }
}

int notSrc[N], notSnk[N];

void tarjan()
{
    vid++;
    tim = componentNum = stcksz = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] != vid)
            sccdfs(i);
    }

    for (int u = 0; u < n; ++u)
    {
        for (int j = 0; j < adj[u].size(); j++)
        {
            int v = adj[u][j];
            if (cmpId[u] == cmpId[v])
                continue;
            notSrc[cmpId[v]] = vid;
            notSnk[cmpId[u]] = vid;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifdef ONLINE_JUDGE

#endif

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        adj[a].push_back(b);
    }

    tarjan();

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (cmpId[i] == 0)
        {
            ans.push_back(i + 1);
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans)
    {
        cout << x << " ";
    }

    return 0;
}