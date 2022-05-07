// problem link:   https://atcoder.jp/contests/dp/tasks/dp_f

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a, b;

vector<vector<int>> dp;

int solve(int i, int j)
{
    if (i >= a.length() || j >= b.length())
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int res = 0;

    if (a[i] == b[j])
    {

        res = max({solve(i + 1, j + 2), solve(i + 2, j + 1), solve(i + 1, j + 1)}) + 1;
    }
    else
    {
        res = max({solve(i + 1, j), solve(i, j + 1)});
    }
    return dp[i][j] = res;
}

string build(int i, int j)
{
    if (i >= a.length() || j >= b.length())
    {
        return "";
    }

    string res = "";

    if (a[i] == b[j])
    {

        if (solve(i + 1, j + 2) + 1 == dp[i][j])
        {
            res = build(i + 1, j + 2);
        }
        else if (solve(i + 2, j + 1) + 1 == dp[i][j])
        {
            res = build(i + 2, j + 1);
        }
        else if (solve(i + 1, j + 1) + 1 == dp[i][j])
        {
            res = build(i + 1, j + 1);
        }

        res = a[i] + res;
    }
    else
    {
        if (solve(i + 1, j) == dp[i][j])
        {
            res = build(i + 1, j);
        }
        else if (solve(i, j + 1) == dp[i][j])
        {
            res = build(i, j + 1);
        }
    }
    return res;
}

int main()
{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    // #endif

    cin >> a >> b;
    dp.clear();
    dp.resize(a.length(), vector<int>(b.length(), -1));
    // cout << solve(0, 0)<<endl;
    solve(0, 0);
    cout << build(0, 0);

    return 0;
}
