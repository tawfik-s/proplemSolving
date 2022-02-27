
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

    int n,m,number=0;
    while(cin>>n,n) {
        number++;
        map<string, int> mp;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            mp[s] = i;
        }
        vector<vector<double>> cost(n, vector<double>(n, 0));
        for (int i = 0; i < n; i++) {
            cost[i][i] = 1;
        }
        cin >> m;
        while (m--) {
            string a, b;
            double f;
            cin >> a >> f >> b;
            cost[mp[a]][mp[b]] = max(cost[mp[a]][mp[b]], f);
        }
        for (int k = 0; k < n; k++)
            for (int u = 0; u < n; u++)
                for (int v = 0; v < n; v++)
                    cost[u][v] = max(cost[u][v], cost[u][k] * cost[k][v]);

        bool flag = false;

        for (int i = 0; i < n; i++) {
            if (cost[i][i] > 1) {
                cout << "Case "<<number << ": Yes\n";
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << "Case "<<number << ": No\n";


    }





    return 0;
}
