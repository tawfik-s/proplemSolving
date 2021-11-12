#include <bits/stdc++.h>
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;
typedef long long ll;

const int N = 1e3 + 5, M = 1e3 + 5, MOD = 1e9 + 7, OO = 0x3f3f3f3f;
const ll LOO = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-8;

string a, b;
int n, m;
vector<vector<int>> mem;

int solve(int i, int j)
{
    if (i == n || j == m)
        return 0;
    if (mem[i][j] != -1)
        return mem[i][j];
    if (a[i] == b[j])
        return mem[i][j] = 1 + solve(i + 1, j + 1);
    else
    {
        int op1 = solve(i, j + 1);
        int op2 = solve(i + 1, j);
        return mem[i][j] = max(op1, op2);
    }
}

int main()
{
    FIO
            //    freopen("input.txt","rt",stdin);
            //    freopen("output.txt","wt",stdout);
            cin >>
        a >> b;
    n = a.length();
    m = b.length();
    mem = vector<vector<int>>(n, vector<int>(m, -1));
    cout << solve(0, 0) << '\n';

    return 0;
}