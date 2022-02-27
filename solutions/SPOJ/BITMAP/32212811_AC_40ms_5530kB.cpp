// Author : tawfik shalash
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
#include<bits/stdc++.h>
//cpp 11
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
#define fast     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"

using namespace std;


int n=0,m=0;

bool test(int x,int y)
{
    return x>=0&&x<n&&y>=0&&y<m;
}


int main() {

    fast
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

int w;
cin>>w;
while(w--) {
    int xn[4] = {1, -1, 0, 0};
    int yn[4] = {0, 0, 1, -1};
    cin >> n >> m;
    queue<pair<int, int>> qu;
    string s;
    vector<string> v(n);
    vector<vector<int>> vis(n + 2, vector<int>(m + 2, -1));
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '1') {
                vis[i][j] = 0;
                qu.push({i, j});
            }
        }
    }
    while (!qu.empty()) {
        pair<int, int> node = qu.front();
        int x = node.first;
        int y = node.second;
        qu.pop();
        for (int i = 0; i < 4; i++) {
            if (test(x + xn[i], y + yn[i]) && vis[x + xn[i]][y + yn[i]]==-1) {
                qu.push({x + xn[i], y + yn[i]});
                vis[x + xn[i]][y + yn[i]] = vis[x][y] + 1;
            }

        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << vis[i][j] << " ";
        }
        cout << endl;
    }


}


    return 0;



}
