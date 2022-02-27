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
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef set<int> si;
typedef pair<ll,int> ii;
const ll INF=1e14;
#define fast     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"

double memo[(int)1e6];
int n, x[30], y[30];

double dist(int i, int j) {
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

double solve(int mask) {
    if (mask == (1 << n) - 1)
        return 0;
    if (memo[mask] != 0)
        return memo[mask];

    double ans = 2e9;
    int p1, p2;

    for (p1 = 0; p1 < n; p1++) {
        if (!(1 & (mask >> p1)))
            break;
    }
    for (p2 = p1 + 1; p2 < n; p2++) {
        if (!(1 & (mask >> p2))) {
            ans = min(ans, dist(p1, p2) + solve(mask | (1 << p1) | (1 << p2)));
        }
    }

    return memo[mask] = ans;
}

int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    string s;    int count = 0;

    while (cin>>n, n) {
        count++;
        n *= 2;
        for (int i = 0; i < n; i++) {
            cin>>s>>x[i]>>y[i];
        }

        memset(memo, 0, sizeof(memo));
        double ans = solve(0);
        cout<<"Case "<<count<<": "<<fixed<<setprecision(2)<<ans<<endl;
    }


    return 0;
}
