#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

struct suff
{
    string s;
    int n;
    vector<int> p, c;
    bool initialized = false;

    void print()
    {
        for (int i = 0; i < n; i++)
        {
            cout << p[i] << " " << s.substr(p[i], n - p[i]) << endl;
        }
    }

    void radix_sort(vector<pair<pair<int, int>, int>> &a)
    {
        {
            vector<int> cnt(n, 0);
            for (auto u : a)
            {
                cnt[u.first.second]++;
            }
            vector<pair<pair<int, int>, int>> a_new(n);
            vector<int> pos(n);
            pos[0] = 0;
            for (int i = 1; i < n; i++)
                pos[i] = pos[i - 1] + cnt[i - 1];

            for (auto x : a)
                a_new[pos[x.first.second]++] = x;
            a = a_new;
        }
        {
            vector<int> cnt(n, 0); // for groubs
            for (auto u : a)
            {
                cnt[u.first.first]++;
            }
            vector<pair<pair<int, int>, int>> a_new(n);
            vector<int> pos(n);
            pos[0] = 0;
            for (int i = 1; i < n; i++)
                pos[i] = pos[i - 1] + cnt[i - 1];

            for (auto x : a)
                a_new[pos[x.first.first]++] = x;
            a = a_new;
        }
    }

    void build()
    {
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
            {
                c[p[i]] = c[p[i - 1]];
            }
            else
            {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }

        int k = 0;

        while ((1 << k) < n)
        {

            vector<pair<pair<int, int>, int>> a(n);
            for (int i = 0; i < n; i++)
            {
                a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
            }
            // sort(a.begin(), a.end());
            radix_sort(a);
            for (int i = 0; i < n; i++)
                p[i] = a[i].second;

            c[p[0]] = 0;

            for (int i = 1; i < n; i++)
            {
                if (a[i].first == a[i - 1].first)
                {
                    c[p[i]] = c[p[i - 1]];
                }
                else
                {
                    c[p[i]] = c[p[i - 1]] + 1;
                }
            }
            k++;
        }
    }

    void init(string st)
    {
        s = st;
        s += '$';
        n = s.size();
        p.clear();
        c.clear();
        p.resize(n);
        c.resize(n);
        build();
        initialized = true;
    }

    vector<int> getSuffixArray()
    {
        return p;
    }
    vector<int> getSuffixArray(string str)
    {
        init(str);
        return p;
    }

} suffix;

int main()
{

    string s = "ababba";
    // cin>>s;

    suffix.init(s);
    suffix.print();

    return 0;
}