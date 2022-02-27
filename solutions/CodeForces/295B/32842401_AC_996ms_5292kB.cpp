
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
    cin>>n;
    vector<vector<int>>adj(n,vector<int>(n));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>adj[i][j];
        }
    }
    vector<int>rem(n);
    vector<bool>added(n,false);
    for(int i=0;i<n;i++)
        cin>>rem[i];
    reverse(rem.begin(),rem.end());
    vector<ll>res;
    for(int i=0;i<n;i++) {
        ll k=rem[i]-1;
        ll sum=0;
        added[k]=1;
        for (int u = 0; u < n; u++)
            for (int v = 0; v < n; v++) {
                adj[u][v] = min(adj[u][v], adj[u][k] + adj[k][v]);
                if(added[u]&&added[v])
                sum+=adj[u][v];
            }
        res.push_back(sum);
    }
    reverse(res.begin(),res.end());
    for(auto res:res)
    {
        cout<<res<<" ";
    }








return 0;
}
