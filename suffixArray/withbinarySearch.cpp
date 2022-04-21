#include <bits/stdc++.h>
#include <ext/numeric>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;

struct SuffixArray
{

    vector<int> p, c; // p is prefix  and c is the group
    string s;

    void radix_sort(vector<array<int, 3>> &a)
    {
        int n = a.size();
        {
            vector<int> cnt(n, 0);
            for (auto u : a)
                cnt[u[1]]++;

            vector<array<int, 3>> a_new(n);
            vector<int> pos(n);

            pos[0] = 0;
            for (int i = 1; i < n; i++)
                pos[i] = pos[i - 1] + cnt[i - 1];

            for (auto x : a)
                a_new[pos[x[1]]++] = x;

            a = a_new;
        }

        {
            vector<int> cnt(n, 0);
            for (auto u : a)
                cnt[u[0]]++;

            vector<array<int, 3>> a_new(n);
            vector<int> pos(n);

            pos[0] = 0;
            for (int i = 1; i < n; i++)
                pos[i] = pos[i - 1] + cnt[i - 1];

            for (auto x : a)
                a_new[pos[x[0]]++] = x;

            a = a_new;
        }
    }

    void build()
    {

        // k = 0 ;
        s += "$";
        int n = s.size();
        vector<pair<char, int>> a(n);

        for (int i = 0; i < n; i++)
            a[i] = {s[i], i};
        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++)
            p[i] = a[i].second;

        c[p[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i].first == a[i - 1].first)
                c[p[i]] = c[p[i - 1]];
            else
                c[p[i]] = c[p[i - 1]] + 1;
        }

        int k = 0;
        while ((1 << k) < n)
        {

            vector<array<int, 3>> a(n);

            for (int i = 0; i < n; i++)
            {
                array<int, 3> in;
                in[0] = c[i];
                in[1] = c[(i + (1 << k) % n) % n];
                in[2] = i;

                a[i] = in;
            }

            radix_sort(a);
            for (int i = 0; i < n; i++)
                p[i] = a[i][2];

            c[p[0]] = 0;
            for (int i = 1; i < n; i++)
            {
                if (a[i][0] == a[i - 1][0] && a[i - 1][1] == a[i][1])
                    c[p[i]] = c[p[i - 1]];
                else
                    c[p[i]] = c[p[i - 1]] + 1;
            }

            k++;
        }
    }

    void init(string &str)
    {
        s = str;
        p.resize(s.size() + 1);
        c.resize(s.size() + 1);
        build();
    }
    int can(int mid, string &pat)
    {

        int i = 0;
        int j = p[mid];

        for (; i < pat.length() && j < s.length(); i++, j++)
        {
            if (pat[i] > s[j])
            {
                return 1;
            }
            else if (pat[i] < s[j])
            {
                return 2; // for right
            }
        }

        if (i == pat.length())
        {
            return 3;
        }
        else
        {
            return 1;
        }
    }

    bool found(string &pat)
    {
        int l = 0, r = p.size();
        while (r >= l)
        {
            int mid = (r + l) / 2;
            int res = can(mid, pat);
            if (res == 3)
            {
                return 1;
            }
            else if (res == 1)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return 0;
    }

} suff;

int main()
{

    string str;
    cin >> str;

    suff.init(str);

    int T;
    cin >> T;
    while (T--)
    {

        string pat;
        cin >> pat;

        if (suff.found(pat))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
