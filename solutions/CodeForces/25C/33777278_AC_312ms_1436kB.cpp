#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


/*


*/
int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif


    int n;

    scanf("%d",&n);
    vector<vector<int>> adj;
    adj.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d",&adj[i][j]);
        }

    int q;
        cin>>q;
        while(q--) {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(c<adj[a-1][b-1]) {
                adj[a - 1][b - 1] = min(c, adj[a - 1][b - 1]);
                adj[b - 1][a - 1] = min(c, adj[b - 1][a - 1]);
                    for (int u = 0; u < n; u++)
                        for (int v = 0; v < n; v++) {
                            adj[u][v] = min(adj[u][v], adj[u][a-1]+c+ adj[b-1][v]);
                            adj[v][u] = min(adj[v][u], adj[v][b-1]+c+ adj[a-1][u]);
                        }
            }
            ll sum=0;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    sum+=adj[i][j];
                }
            cout<<sum/2<<" ";

        }



return 0;
}