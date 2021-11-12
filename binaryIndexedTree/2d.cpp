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
vector<vector<int>> arr;
vector<vector<ll>> bit;

void add(int x, int y, int diff)
{
    for (int i = x; i <= n; i += (i & -i))
        for (int j = y; j <= m; j += (j & -j))
            bit[i][j] += diff;
}

void build()
{
    bit = vector<vector<ll>>(n + 1, vector<ll>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            add(i, j, arr[i][j]);
}

ll prefixSum(int x, int y)
{
    ll sum = 0;
    for (int i = x; i >= 1; i -= (i & -i))
        for (int j = y; j >= 1; j -= (j & -j))
            sum += bit[i][j];
    return sum;
}

ll rangeSum(int x1, int y1, int x2, int y2)
{
    return prefixSum(x2, y2) - prefixSum(x1 - 1, y2) - prefixSum(x2, y1 - 1) + prefixSum(x1 - 1, y1 - 1);
}

int main()
{
    FIO
            //    freopen("input.txt","rt",stdin);
            //    freopen("output.txt","wt",stdout);

            cin >>
        n >> m;
    arr = vector<vector<int>>(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];
    build();
    int q;
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << rangeSum(x1, y1, x2, y2) << '\n';
        }
        else
        {
            int x, y, newVal;
            cin >> x >> y >> newVal;
            add(x, y, newVal - arr[x][y]);
            arr[x][y] = newVal;
        }
    }
    return 0;
}
