
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


int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    string s;
    cin >> s;
    int n = s.length();
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            vector<vector<int>> adj(10, vector<int>(10, 1e9));
            for (int i = 0; i < 10; i++)
            {
                adj[i][(i + x) % 10] = 1;
                adj[i][(i + y) % 10] = 1;
            }
            for (int k = 0; k < 10; k++) {
                for (int u = 0; u < 10; u++) {
                    for (int v = 0; v < 10; v++) {
                        adj[u][v] = min(adj[u][v], adj[u][k] + adj[k][v]);
                    }
                }
            }
            ll res = 0;
            for (int i = 1; i < n && res != -1; i++) {
                if (adj[s[i - 1] - '0'][s[i] - '0'] >= 1e9) {
                    res = -1;
                }
                else {
                    res += adj[s[i - 1] - '0'][s[i] - '0'] - 1;
                }
            }
            cout << res << ' ';
        }
        cout << endl;
    }


    return 0;
}