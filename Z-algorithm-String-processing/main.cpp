#include <bits/stdc++.h>

using namespace std;

vector<int> buildZ(string s)
{
    vector<int> Z;
    int n = s.length();
    Z = vector<int>(n);
    int l = 0, r = 0;
    Z[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int k = i - l;
        if (i >= r || i + Z[k] >= r)
        {
            l = i;
            r = max(r, i);
            while (r < n && s[r - l] == s[r])
                r++;
            Z[i] = r - l;
        }
        else
            Z[i] = Z[k];
    }
    return Z;
}

int main()
{
    string s = "aabxaabxzaabxaabx";
    vector<int> Z;
    Z = buildZ(s);
    for (auto x : Z)
    {
        cout << x << " ";
    }

    return 0;
}