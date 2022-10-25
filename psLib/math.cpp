#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class math
{

    ll fact(ll x)
    {
        int res = 1, i;
        for (i = 2; i <= x; i++)
            res *= i;
        return res;
    }

    ll ncr(ll n, ll r)
    {
        return (fact(n) / ((fact(n - r)) * fact(r)));
    }

    ll npr(ll n, ll r)
    {
        return (fact(n) / fact(n - r));
    }

    int gcd(int a, int b)
    {
        return (!b) ? a : gcd(b, a % b);
    }

    int lcm(int a, int b) // least common multiplicator
    {
        return (a / gcd(a, b)) * b;
    }

    int mod(int a, int b)
    {
        return ((b + (a % b)) % b);
    }
};
