#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define int long long

struct segtree
{
    int size;
    vector<int> tree;

    void init(int n)
    {
        size = n;
        tree.resize(4 * size + 4, 0);
    }
    void build(vector<int> &arr, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)arr.size())
            {
                tree[x] = arr[lx];
            }
        }
        else
        {
            int mid = (lx + rx) >> 1;
            build(arr, 2 * x + 1, lx, mid);
            build(arr, 2 * x + 2, mid, rx);
            tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
        }
    }
    void build(vector<int> &arr)
    {
        build(arr, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        { // reach the element
            tree[x] = v;
            return;
        }
        int mid = (lx + rx) >> 1;
        if (i < mid)
        {
            set(i, v, 2 * x + 1, lx, mid);
        }
        else
        {
            set(i, v, 2 * x + 2, mid, rx);
        }
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    int sum(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || l >= rx)
            return 0;
        if (lx >= l && rx <= r)
            return tree[x]; // if you are at the segment
        int mid = (lx + rx) >> 1;
        return sum(l, r, 2 * x + 1, lx, mid) + sum(l, r, 2 * x + 2, mid, rx);
    }

    int sum(int l, int r)
    {
        return sum(l, r, 0, 0, size);
    }
};