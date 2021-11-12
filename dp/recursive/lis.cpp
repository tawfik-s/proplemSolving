#include <bits/stdc++.h>
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;
typedef long long ll;

const int N = 1e3 + 5, M = 1e3 + 5, MOD = 1e9 + 7, OO = 0x3f3f3f3f;
const ll LOO = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-8;

int n;
vector<int> arr;
vector<vector<int>> mem;

int solve(int i, int ls)
{
    if (i == n + 1)
        return 0;
    if (mem[i][ls] != -1)
        return mem[i][ls];
    int op1 = (arr[i] > arr[ls]) ? solve(i + 1, i) + 1 : INT_MIN;
    int op2 = solve(i + 1, ls);
    return mem[i][ls] = max(op1, op2);
}

int main()
{
    FIO
            //    freopen("input.txt","rt",stdin);
            //    freopen("output.txt","wt",stdout);
            cin >>
        n;
    arr.resize(n + 1);
    mem = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    arr[0] = 0;
    cout << solve(1, 0) << '\n';

    return 0;
}