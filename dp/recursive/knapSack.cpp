#include <bits/stdc++.h>
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;
typedef long long ll;

const int N = 1e3 + 5, M = 1e3 + 5, MOD = 1e9 + 7, OO = 0x3f3f3f3f;
const ll LOO = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-8;

int n, k;
vector<int> w, v;
vector<vector<int>> mem;

int solve(int i, int remK)
{
    if (i == n)
        return 0;
    if (mem[i][remK] != -1)
        return mem[i][remK];
    int op1 = (remK >= w[i]) ? solve(i + 1, remK - w[i]) + v[i] : INT_MIN;
    int op2 = solve(i + 1, remK);
    return mem[i][remK] = max(op1, op2);
}

int main()
{
    FIO
        //    freopen("input.txt","rt",stdin);
        //    freopen("output.txt","wt",stdout);
        int t;
    cin >> t;
    while (t--)
    {
        cin >> k >> n;
        w.resize(n);
        v.resize(n);
        mem = vector<vector<int>>(n, vector<int>(k + 1, -1));
        for (int i = 0; i < n; i++)
            cin >> w[i] >> v[i];
        cout << "Hey stupid robber, you can get " << solve(0, k) << ".\n";
    }

    return 0;
}