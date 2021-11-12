#include <bits/stdc++.h>
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;
typedef long long ll;

const int N = 1e7 + 5, M = 175, Q = 2e5 + 5, MOD = 1e9 + 7, OO = 0x3f3f3f3f;
const ll LOO = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-8;

void push(vector<ll> &t, vector<ll> &lazy, int v, int vl, int vr)
{
    if (lazy[v] == 0)
        return;
    int vm = (vl + vr) / 2;
    t[v * 2] += (vm - vl + 1) * lazy[v];
    lazy[v * 2] += lazy[v];
    t[v * 2 + 1] += (vr - (vm + 1) + 1) * lazy[v];
    lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
}

void build(vector<int> &a, vector<ll> &t, int v, int vl, int vr)
{
    if (vl == vr)
        t[v] = a[vl];
    else
    {
        int vm = (vl + vr) / 2;
        build(a, t, 2 * v, vl, vm);
        build(a, t, 2 * v + 1, vm + 1, vr);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

void update(vector<ll> &t, vector<ll> &lazy, int v, int vl, int vr, int l, int r, ll toAdd)
{
    if (l > r)
        return;
    if (vl == l && vr == r)
    {
        t[v] += ((vr - vl + 1) * toAdd); // Try to update this node to hold a value representing the whole range value after the update query
        lazy[v] += toAdd;                // Save info needed for update child nodes (propagate)
    }
    else
    {
        push(t, lazy, v, vl, vr);
        int vm = (vl + vr) / 2;
        update(t, lazy, v * 2, vl, vm, l, min(r, vm), toAdd);
        update(t, lazy, v * 2 + 1, vm + 1, vr, max(l, vm + 1), r, toAdd);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

ll get(vector<ll> &t, vector<ll> &lazy, int v, int vl, int vr, int l, int r)
{
    if (l > r)
        return 0;
    if (vl == l && vr == r)
        return t[v];
    push(t, lazy, v, vl, vr);
    int vm = (vl + vr) / 2;
    return get(t, lazy, 2 * v, vl, vm, l, min(r, vm)) +
           get(t, lazy, 2 * v + 1, vm + 1, vr, max(l, vm + 1), r);
}

int main()
{
    FIO
        //    freopen("input.txt","rt",stdin);
        //    freopen("output.txt","wt",stdout);

        int n,
        q;
    cin >> n >> q;
    vector<int> arr(n);
    vector<ll> tree(4 * n + 5), lazy(4 * n + 5);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    build(arr, tree, 1, 0, n - 1);
    while (q--)
    {
        int tp;
        cin >> tp;
        if (tp == 1)
        {
            int l, r, toAdd;
            cin >> l >> r >> toAdd;
            l--, r--;
            update(tree, lazy, 1, 0, n - 1, l, r, toAdd);
        }
        else if (tp == 2)
        {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << get(tree, lazy, 1, 0, n - 1, l, r) << '\n';
        }
    }

    return 0;
}
