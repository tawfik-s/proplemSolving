#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


/*


*/
int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    int t;
    cin >> t;
    int n;
    int number=0;
    while (t--) {
        number++;
        cin >> n;
        vector<vector<int>> adj;
        adj.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cin >> adj[i][j];
            }

        for (int k = 0; k < n; k++)
            for (int u = 0; u < n; u++)
                for (int v = 0; v < n; v++) {
                    adj[u][v] = min(adj[u][v], adj[u][k] + adj[k][v]);
                }
        int q;
        cin >> q;
        ll sum = 0;
        while (q--) {
            int a, b;
            cin >> a >> b;
            sum += adj[a-1][b-1];
        }
        cout<<"Case #"<<number<<": "<<sum<<endl;

    }


    return 0;
}
