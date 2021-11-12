#include <bits/stdc++.h>

using namespace std;

struct query
{
    int l, r, bi, qi;
    query() {}
    query(int _l, int _r, int _q, int sqrt)
    {
        l = _l;
        r = _r;
        qi = _q;
        bi = l / sqrt;
    }

    //operator overloading in struct

    bool operator<(const query &q) const
    {
        if (bi != q.bi)
            return bi < q.bi;
        else
            return r < q.r;
    }
};

int n, sqr, res = 0;
vector<int> arr, ans;
vector<query> queries;
void add(int i)
{
    res += arr[i];
}

void remove(int i)
{
    res -= arr[i];
}
void process()
{
    sort(queries.begin(), queries.end());
    int curL = 1, curR = 0;
    for (query q : queries)
    {
        while (curL < q.l)
            remove(curL++);
        while (curL > q.l)
            add(curL--);
        while (curR < q.r)
            add(curR++);
        while (curR < q.r)
            remove(curR--);
        ans[q.qi] = res;
    }
}

int main()
{
    cin >> n;
    sqr = (int)(ceil(sqrt(n)));
    arr = vector<int>(n);
    for (int &x : arr)
        cin >> x;
    int m;
    cin >> m;
    queries = vector<query>(m);
    ans.resize(m);
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        queries[i] = query(l, r, i, sqr);
    }
    process();
    for (int i = 0; i < m; i++)
    {
        cout << ans[i] << '\n';
    }
}
