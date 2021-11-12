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
        int n = 7489;
    int coins[] = {1, 5, 10, 25, 50};
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j <= n; j++)
            if (j + coins[i] <= n)
                dp[j + coins[i]] += dp[j];
    int a;
    while (cin >> a)
        cout << dp[a] << '\n';

    return 0;
}