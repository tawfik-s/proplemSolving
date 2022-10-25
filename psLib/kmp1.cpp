#include <bits/stdc++.h>

using namespace std;

vector<int> computePrefix(string pat)
{
    int m = pat.length();
    vector<int> longestPrefix(m);

    for (int i = 1, k = 0; i < m; i++)
    {
        while (k > 0 && pat[k] != pat[i])
            k = longestPrefix[k - 1];

        if (pat[i] == pat[k])
        {
            longestPrefix[i] = ++k;
        }
        else
        {
            longestPrefix[i] = k;
        }
    }

    return longestPrefix;
}

void KMP(string str, string pat)
{
    int n = str.length();
    int m = pat.length();
    vector<int> longestPrefix = computePrefix(pat);
    for (int i = 1, k = 0; i < n; i++)
    {

        while (k > 0 && pat[k] != str[i])
        {
            k = longestPrefix[k - 1];
        }

        if (pat[k] == str[i])
        {
            k++;
        }
        if (k == m)
        {
            cout << i - m + 1 << endl;
            k = longestPrefix[k - 1];
        }
    }
}

int main()
{

    string a, b;
    cin >> a >> b;

    computePrefix(b);
    KMP(a, b);

    return 0;
}