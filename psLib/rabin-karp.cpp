#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5 + 5, M = 1e3 + 5, MOD = 1e9 + 7, OO = 0x3f3f3f3f;
const ll LOO = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-8;

ll egcd(ll a, ll b, ll &x, ll &y)
{ /// ax + by = gcd(a,b)
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll g = egcd(b, a % b, y, x);
    y -= (a / b) * x;
    return g;
}

ll modInverse(ll a, ll m)
{ /// (a/b)%m = ((a%m)*(modInverse(b)%m))%m
    ll x, y, g;
    g = egcd(a, m, x, y);
    if (g > 1)
        return -1;
    return (x + m) % m;
}

ll fixMod(ll a, ll m)
{
    return (a + m) % m;
}

ll pushBack(ll h, ll x, ll p, char ch)
{
    return (((h * x) % p) + ch) % p;
}

ll pushFront(ll h, ll xp, ll p, char ch)
{ // xp=XP[len]
    return (h + (xp * ch) % p) % p;
}

ll popBack(ll h, ll x, ll p, char ch)
{
    return (fixMod(h - ch, p) * modInverse(x, p)) % p;
}

ll popFront(ll h, ll xp, ll p, char ch)
{ // xp=XP[len-1]
    return fixMod(h - ((xp * ch) % p), p);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifdef ONLINE_JUDGE

#endif

    int x = 128, x2 = 133, p1 = 1e9 + 7, p2 = 1e9 + 9;
    vector<ll> XP1(1e5 + 1), XP2(1e5 + 1);
    XP1[0] = XP2[0] = 1;
    for (int i = 1; i <= 100000; i++)
    {
        XP1[i] = (XP1[i - 1] * x) % p1;
        XP2[i] = (XP2[i - 1] * x2) % p2;
    }

    string s;
    while (true)
    {
        s = "sbbabba";
        int h1f = 0, h2f = 0, h1l = 0, h2l = 0;
        int n = s.length();
        int f = n;
        for (int i = n - 1; i >= 0; i--)
        {
            h1f = pushBack(h1f, x, p1, s[i]);
            h2f = pushBack(h2f, x2, p2, s[i]);
            h1l = pushFront(h1l, XP1[n - i - 1], p1, s[i]);
            h2l = pushFront(h2l, XP2[n - i - 1], p2, s[i]);

            if (h1f == h1l && h2l == h2f)
            {
                f = i;
            }
        }
        string last = s.substr(0, f);
        reverse(last.begin(), last.end());
        cout << s << last << endl;
    }

    return 0;
}