// Author : tawfik shalash
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> ii;
const int INF = (int)1e9;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl "\n"
int n, m;

vector<vector<ii>> adjList;
void dijksta(int s, int sc)
{
    vi dist(n, INF);
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, s});
    while (!pq.empty())
    {
        ii front = pq.top();
        pq.pop();
        if (front.second == sc)
        {
            cout << front.first << endl;
            return;
        }
        int d = front.first, u = front.second;
        if (d > dist[u])
            continue;
        for (auto v : adjList[u])
        {
            if (dist[u] + v.second < dist[v.first])
            {
                dist[v.first] = dist[u] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }
    cout << "NONE\n";
}
int main()
{

    fast
#ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        adjList.clear();
        int sr, sc;
        cin >> n >> m;
        cin >> sr >> sc;
        adjList.resize(n);
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            adjList[--a].push_back({--b, c});
            adjList[b].push_back({a, c});
        }
        sr--;
        sc--;
        dijksta(sr, sc);
    }

    return 0;
}
