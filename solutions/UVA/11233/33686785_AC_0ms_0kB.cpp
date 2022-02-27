
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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, m;
    string str,str2;
    while(cin>>n>>m) {
        map<string, string> mp;
        while (n--) {
            cin >> str >> str2;
            mp[str] = str2;
        }
        while (m--) {
            cin >> str;
            if (mp.find(str) != mp.end()) {
                cout << mp[str] << endl;
                continue;
            }
            int siz = str.length();
            if (str[siz - 1] == 'y' && str[siz - 2] != 'a' && str[siz - 2] != 'e'
                && str[siz - 2] != 'i' && str[siz - 2] != 'o' && str[siz - 2] != 'u')
            {
                str.pop_back();
                str+="ies";
            } else if (str[siz - 1] == 'o' || str[siz - 1] == 's' || str[siz - 1] == 'x')
            {
                str+="es";
            } else if (siz >= 2 && ((str[siz - 2] == 'c' && str[siz - 1] == 'h') || (str[siz - 2] == 's' && str[siz - 1] == 'h'))) {
                str+="es";
            } else {
                str += 's';
            }
            cout << str << endl;
        }
    }

    return 0;
}

