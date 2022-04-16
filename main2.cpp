#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll N = 200000 + 15, MOD = 1e9 + 7, base = 30, INF = 1e18;

vector<vector<ll>> floyed(vector<vector<ll>> dis)
{

    //    for (int i = 0; i < dis.size(); i++)
    //     for (int j = 0; i < dis.size(); i++)
    //         d[i][j] = INF;

    int n = dis.size();

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dis[i][j] == 0 || dis[i][k] == 0 || dis[k][j] == 0)
                    continue;
                dis[i][j] = min({dis[i][j], dis[i][k] + dis[k][j]});
            }
        }
    }

    return dis;
}

void Solve(int tc)
{

    int n;
    cin >> n;

    vector<vector<ll>> dis(n, vector<ll>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dis[i][j];

    vector<vector<ll>> ans = floyed(dis);

    int ok = 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (ans[i][j] != dis[i][j])
            {
                ok = 0;
                break;
            }

    if (!ok)
        return cout << "-1", void();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }

        cout << "\n";
    }
}

int main()
{

    // 	freopen( "input.txt" , "r", stdin);
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1, tc = 1, n;
    // cin>>t;
    while (t--)
        Solve(tc++);
}