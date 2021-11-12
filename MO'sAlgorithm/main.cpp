#include <bits/stdc++.h>
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;
typedef long long ll;

const int N = 1e5 + 5, M = 1e3 + 5, MOD = 1e9 + 7, OO = 0x3f3f3f3f;
const ll LOO = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-8;

struct query
{
    int l, r, bi, qi;
    query() {}
    query(int _l, int _r, int _qi, int sqr)
    {
        l = _l, r = _r, qi = _qi, bi = l / sqr;
    }
    bool operator<(const query &q) const
    {
        if (bi != q.bi)
            return bi < q.bi;
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
            add(--curL);
        while (curR < q.r)
            add(++curR);
        while (curR > q.r)
            remove(curR--);
        ans[q.qi] = res;
    }
}

int main()
{
    FIO
            //    freopen("input.txt","rt",stdin);
            //    freopen("output.txt","wt",stdout);
            cin >>
        n;
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
        --l, --r;
        queries[i] = query(l, r, i, sqr);
    }
    process();
    for (int i = 0; i < m; i++)
        cout << ans[i] << '\n';

    return 0;
}