// problem link:   https://atcoder.jp/contests/dp/tasks/dp_f

// this solution make time limit in 7 test cases;

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a, b;

vector<vector<string>> dp;

string solve(int i, int j)
{
    if (i >= a.length() || j >= b.length())
    {
        return "";
    }

    if (dp[i][j] != "#")
    {
        return dp[i][j];
    }
    string res = "";

    if (a[i] == b[j])
    {

        res = a[i] + solve(i + 1, j + 1);
    }
    else
    {
        string a = solve(i + 1, j);
        string b = solve(i, j + 1);

        if (a.length() > b.length())
        {
            res += a;
        }
        else
        {
            res += b;
        }
    }
    return dp[i][j] = res;
}

int main()
{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    cin >> a >> b;
    dp.clear();
    dp.resize(a.length(), vector<string>(b.length(), "#"));
    // cout << solve(0, 0)<<endl;
    cout << solve(0, 0);
    // cout << build(0, 0);

    return 0;
}