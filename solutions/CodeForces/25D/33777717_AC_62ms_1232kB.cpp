
/*
author: tawfik shalash
─▄█▄─█▀█▀█─▄█▄
▀▀████▄█▄████▀▀
─────▀█▀█▀

*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> ii;
const ll INF = 1e14;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl "\n"
ll M = 1e9 + 7;
ll OO = 1e9;
ll MOD = 1e9 + 7;
int Max = 1e9, q;


int n;
vector<int> par;


int findParent(int u) {
    if (u == par[u]) return u;
    return par[u] = findParent(par[u]);
}

void join(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a != b)
        par[b] = a;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    cin >> n;
    par = vector<int>(n);
    vector<ii> res;
    iota(par.begin(), par.end(), 0);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (findParent(a) == findParent(b)) { res.push_back({a, b}); }
        else { join(a, b); }
    }
    set<int> SET;
    for (int i = 0; i < n; i++) { SET.insert(findParent(i)); }

    cout << res.size() << endl; //number of collections

    for (auto p: res) {
        cout << p.first + 1 << ' ' << p.second + 1 << ' ' << (*SET.begin()) + 1 << ' ';
        SET.erase(*SET.begin());
        cout << (*SET.begin()) + 1 << '\n';
    }

    return 0;

}
