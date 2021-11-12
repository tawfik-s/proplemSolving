#include <bits/stdc++.h>
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;
typedef long long ll;

const int N = 2e5 + 5, M = 1e3 + 5, MOD = 1e9 + 7, OO = 0x3f3f3f3f;
const ll LOO = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-8;

int main()
{
    FIO
        //    freopen("input.txt","rt",stdin);
        //    freopen("output.txt","wt",stdout);

        int t;
    cin >> t;
    while (t--)
    {
        int k, n;
        cin >> k >> n;
        vector<int> w(n), v(n);
        for (int i = 0; i < n; i++)
            cin >> w[i] >> v[i];

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                // pick
                if (j + w[i] <= k)
                    dp[i + 1][j + w[i]] = max(dp[i + 1][j + w[i]], dp[i][j] + v[i]);
                // leave
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            }
        }
        cout << "Hey stupid robber, you can get " << dp[n][k] << ".\n";
    }

    return 0;
}