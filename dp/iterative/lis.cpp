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

        int n;
    cin >> n;
    vector<int> arr(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    arr[0] = 0;
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (arr[i] > arr[j])
                dp[i + 1][i] = max(dp[i + 1][i], dp[i][j] + 1);
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }
    }
    int mx = 1;
    for (int j = 0; j <= n; j++)
        mx = max(mx, dp[n + 1][j]);
    cout << mx << '\n';

    return 0;
}