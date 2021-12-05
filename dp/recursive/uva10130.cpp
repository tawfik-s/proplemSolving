
/*
author: tawfik shalash
─▄█▄─█▀█▀█─▄█▄
▀▀████▄█▄████▀▀
─────▀█▀█▀

*/
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int n, m;
vector<pair<int, int>> v;
int dp[2000][200];

int solve(int ind, int w) {
    if (ind == n || w == 0) {
        return 0;
    }
    if (dp[ind][w] != -1) {
        return dp[ind][w];
    }
    int x = solve(ind + 1, w);
    if (w - v[ind].second >= 0)
        x = max(x, (solve(ind + 1, w - v[ind].second) + v[ind].first));

    return dp[ind][w] = x;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    bool flag = false;
    while (t--) {

        cin >> n;
        v.clear();
        v.resize(n+1);
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            v[i]={a, b};
        }
        int sum = 0;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int a;
            cin >> a;
            sum += solve(0, a);
        }


        cout << sum<<endl;

    }


    return 0;

}