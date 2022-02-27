
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
const int N = 2e5 + 5, M = 17 + 5, MOD = 1000000007 , OO = 0x3f3f3f3f;
int n, k, d;
ll dp[105][105][2];
ll solve(int sum, int lev,bool cnt) {
    if (sum > n)return 0;
    if (sum == n&&cnt)
        return 1;
    if(dp[sum][lev][cnt]!=-1)return dp[sum][lev][cnt];
    ll ret = 0;
    for (int i = 1; i <= k; i++)
        ret += solve(sum + i,lev+1, cnt|(i>=d));

    return dp[sum][lev][cnt]=ret%MOD;
}

int main() {
   ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    memset(dp,-1,sizeof(dp));
    cin >> n >> k >> d;
    cout << solve(0,0, 0);



    return 0;
}

