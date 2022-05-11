#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string s1, string s2, vector<vector<int>> &dp)
{
    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;

            dp[i][j] = max({dp[i][j], dp[i][j - 1], dp[i - 1][j]});
        }
    }
    return dp[s1.size()][s2.size()];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    int count = longestCommonSubsequence(s1, s2, dp); // This will give count of lcs and change the dp vector

    string s = "";
    int i = s1.size(), j = s2.size();
    while (i > 0 && j > 0)
    {
        if (dp[i - 1][j - 1] + 1 == dp[i][j] && dp[i - 1][j] + 1 == dp[i][j] && dp[i][j - 1] + 1 == dp[i][j])
        {
            i--;
            j--;
            s = s1[i] + s; // As we are travelling backward reverse the string
        }
        else if (dp[i][j - 1] > dp[i - 1][j])
            j--;
        else
            i--;
    }
    cout << s << endl;

    return 0;
}