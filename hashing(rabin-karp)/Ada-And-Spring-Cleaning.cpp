// https://vjudge.net/contest/488773#problem/G
#include <bits/stdc++.h>
#include <ext/numeric>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;

const int MOD = 1e9 + 7, OO = 0x3f3f3f3f;
const ll LOO = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-8;

const int N = 3e4 + 5, M = 1e3 + 5;

struct mul
{
    int mod;
    int operator()(int a, int b)
    {
        return a * 1LL * b % mod;
    }
    mul(int _mod) : mod(_mod){};
};

struct add
{
    int mod;
    int operator()(int a, int b)
    {
        return (a + b) % mod;
    }
    add(int _mod) : mod(_mod){};
};

struct sub
{
    int mod;
    int operator()(int a, int b)
    {
        return (a + mod - b) % mod;
    }
    sub(int _mod) : mod(_mod){};
};

int identity_element(const mul &)
{
    return 1;
}

mul m(MOD);
add a(MOD);
sub s(MOD);

int modInverse(int base, int mod)
{
    return power(base, mod - 2, mul(MOD));
}

const int BASE = 128, INV = modInverse(BASE, MOD);
char str[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int h1 = 0,
        h2 = 0, p = 1;
    int k;
    cin >> k >> str;
    for (int i = 0, j = k - 1; i < k; i++, j--)
    {
        h1 = m(h1, BASE);
        h1 = a(h1, str[i]);
        h2 = m(h2, BASE);
        h2 = a(h2, str[j]);
        if (i)
            p = m(p, BASE);
    }
    int res = 0;
    if (h1 == h2)
        res++;
    for (int i = k, j = 0; str[i - 1]; i++, j++)
    {

        h1 = s(h1, m(p, str[j]));
        h1 = m(h1, BASE);
        h1 = a(h1, str[i]);

        h2 = s(h2, str[j]);
        h2 = m(h2, INV);
        h2 = a(h2, m(p, str[i]));

        if (h1 == h2)
            res++;
    }
    cout << res << '\n';

    return 0;
}