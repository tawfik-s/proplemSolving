
/*
author: tawfik shalash
　　██░▀██████████████▀░██
　　█▌▒▒░████████████░▒▒▐█
　　█░▒▒▒░██████████░▒▒▒░█
　　▌░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▐
　　░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░
　 ███▀▀▀██▄▒▒▒▒▒▒▒▄██▀▀▀██
　 ██░░░▐█░▀█▒▒▒▒▒█▀░█▌░░░█
　 ▐▌░░░▐▄▌░▐▌▒▒▒▐▌░▐▄▌░░▐▌
　　█░░░▐█▌░░▌▒▒▒▐░░▐█▌░░█
　　▒▀▄▄▄█▄▄▄▌░▄░▐▄▄▄█▄▄▀▒
　　░░░░░░░░░░└┴┘░░░░░░░░░
　　██▄▄░░░░░░░░░░░░░░▄▄██
　　████████▒▒▒▒▒▒████████
　　█▀░░███▒▒░░▒░░▒▀██████
　　█▒░███▒▒╖░░╥░░╓▒▐█████
　　█▒░▀▀▀░░║░░║░░║░░█████
　　██▄▄▄▄▀▀┴┴╚╧╧╝╧╧╝┴┴███
　　██████████████████████
     عك وليس كله كويس
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<ll, int> ii;
const ll INF = 1e14;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl "\n"
ll M = 1e9 + 7;
ll OO = 1e9;
const ll N=1e5+9;
ll MOD=1e9+7;

struct query
{
    int l, r, bi, qi;
    query() {}
    query(int _l, int _r, int _q, int sqrr)
    {
        l = _l;
        r = _r;
        qi = _q;
        bi = l / sqrr;
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

ll n, sqr, res = 0;
vector<ll> arr, ans,take(1e6+1,0);
vector<query> queries;
void add(int i)
{
    ll x=arr[i]*take[arr[i]]*take[arr[i]];
    res-=x;
    take[arr[i]]++;
    res+=arr[i]*take[arr[i]]*take[arr[i]];
}

void remove(int i)
{
    ll x=arr[i]*take[arr[i]]*take[arr[i]];
    res-=x;
    take[arr[i]]--;
    res+=arr[i]*take[arr[i]]*take[arr[i]];
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
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif


    int m;
        cin >> n;
        cin >> m;
        sqr = (ll)(ceil(sqrt(n)));
        arr = vector<ll>(n);

        for (ll &x : arr)
            cin >> x;

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


    return 0;
}

