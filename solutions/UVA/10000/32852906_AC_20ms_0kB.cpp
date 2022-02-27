
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

    int n,s;int number=0;
    while(cin>>n) {
        if (n == 0)
            return 0;

        number++;
        cin >> s;
        --s;
        int a, b;
        vector<vector<ll>> adj(n);

        while (cin >> a >> b) {
            if (a + b == 0)
                break;
            --a;
            --b;
            adj[a].push_back(b);

        }
        queue<int> qu;
        qu.push(s);
        vector<int> vis(n, 0);
        ll num = 0, val = 0;
        while (!qu.empty()) {
            int node = qu.front();
            qu.pop();
            for (auto v: adj[node]) {
                if (vis[v]<vis[node]+1) {
                    qu.push(v);
                    vis[v] = vis[node] + 1;
                }
            }

        }
        for (int i = 0; i < n; i++)
        {
            if(vis[i]>val)
            {
                val=vis[i];
                num=i;
            }
        }

        cout<<"Case "<<number<<": The longest path from "<<
        s+1<<" has length "<<
        val<<", finishing at "<<num+1<<".\n\n";

    }


    return 0;
}