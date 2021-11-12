#include <bits/stdc++.h>
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;
typedef long long ll;

const int N = 1e5 + 5, M = 1e3 + 5, MOD = 1e9 + 7, OO = 0x3f3f3f3f;
const ll LOO = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-8;

int n;
vector<int> arr;
vector<ll> bit;

void add(int indx, int toAdd)
{
    for (int i = indx; i <= n; i += (i & -i))
        bit[i] += toAdd;
}

void build()
{
    bit = vector<ll>(n + 1, 0);
    for (int i = 1; i <= n; i++)
        add(i, arr[i]);
}

ll prefixSum(int indx)
{
    ll sum = 0;
    for (int i = indx; i >= 1; i -= (i & -i))
        sum += bit[i];
    return sum;
}

ll rangeSum(int l, int r)
{
    return prefixSum(r) - prefixSum(l - 1);
}

int main()
{
    FIO
            //    freopen("input.txt","rt",stdin);
            //    freopen("output.txt","wt",stdout);
            cin >>
        n;
    arr = vector<int>(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    build();
    int q;
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << rangeSum(l, r) << '\n';
        }
        else
        {
            int indx, newVal;
            cin >> indx >> newVal;
            add(indx, newVal - arr[indx]);
            arr[indx] = newVal;
        }
    }

    return 0;
}