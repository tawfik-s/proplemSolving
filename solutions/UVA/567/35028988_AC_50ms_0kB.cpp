#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef set<int> si;
typedef pair<ll,ll> ii;
const int INF=1e9; int N=2e5+10;
#define fast     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"

int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int a;
    int num=1;
while(cin>>a) {
    cout<<"Test Set #"<<num++<<endl;
    vector<vector<int>> adjmat;
    adjmat.resize(20, vector<int>(20, INF));
    for (int i = 0; i < 20; i++)
        adjmat[i][i] = 0;

    for (int i = 0; i < 20-1; i++) {
       if(i!=0)
        cin >> a;
        for (int j = 0; j < a; j++) {
            int b;
            cin >> b;
            b--;
            adjmat[i][b] = 1;
            adjmat[b][i] = 1;
        }
    }


    for (int k = 0; k < 20; k++)
        for (int i = 0; i < 20; i++)
            for (int j = 0; j < 20; j++)
                adjmat[i][j] = min(adjmat[i][j], adjmat[i][k] + adjmat[k][j]);

    int q;
    cin >> q;
    while (q--) {

        int aa, b;

        cin >> aa >> b;
        if(aa<10)
            cout<<" ";

        cout <<aa<<" to ";

        if(b<10)
            cout<<" ";
        cout<<b<<": ";

        aa--;
        b--;

        cout << adjmat[aa][b] << endl;
    }
    cout << endl;
}

    return 0;
}
