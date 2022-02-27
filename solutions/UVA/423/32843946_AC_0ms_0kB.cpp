
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


    int n;
    cin >> n;
    vector<vector<ll>> adj(n, vector<ll>(n));

    for (int i = 0; i < n; i++) {
        adj[i][i] = 0;
        for (int j = 0; j < i; j++) {
            string x;
            cin >> x;
            if (x == "x") {
                adj[i][j] = (ll) 1e14;
                adj[j][i] = (ll) 1e14;
            } else {
                adj[i][j] = stoi(x);
                adj[j][i] = stoi(x);
            }
        }
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

    cout << *max_element(adj[0].begin(), adj[0].end()) << endl;


    return 0;
}
