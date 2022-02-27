
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


int tem[(int) 1e6 + 5];

void kmp(const string &n) {
    int size = n.size();
    int loc = 2;
    int cc = 0;
    tem[0] = -1;
    tem[1] = 0;
    while (loc < size) {
        if (n[loc - 1] == n[cc]) {
            cc = cc + 1;
            tem[loc] = cc;
            ++loc;
        } else if (cc > 0) {
            cc = tem[cc];
        } else {
            tem[loc] = 0;
            ++loc;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    string s;
    while (cin >> s, s != ".") {
        kmp(s);
        int si = s.size() - 1;
        int fi = tem[si];

        if (fi != -1 && s[fi] != s[si]) {
            fi = min(0, fi - 1);
        }

        int step = si - fi;

        cout << (s.size() / step) << '\n';
    }


    return 0;

}
