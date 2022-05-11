// problem link:   https://atcoder.jp/contests/dp/tasks/dp_f

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string longestCommonSubsequence(string s1, string s2, vector<vector<string>> &dp)
{

    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];

            if (dp[i][j - 1].length() == max({dp[i][j].length(), dp[i][j - 1].length(), dp[i - 1][j].length()}))
            {
                dp[i][j] = dp[i][j - 1];
            }
            else if (dp[i - 1][j].length() == max({dp[i][j].length(), dp[i][j - 1].length(), dp[i - 1][j].length()}))
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[s1.size()][s2.size()];
}

int main()
{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<string>> dp(s1.size() + 1, vector<string>(s2.size() + 1, ""));
    string s = longestCommonSubsequence(s1, s2, dp); // This will give count of lcs and change the dp vector

    cout << s << endl;
    return 0;
}