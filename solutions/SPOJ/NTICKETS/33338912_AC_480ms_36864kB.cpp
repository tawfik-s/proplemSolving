
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
     عك وليس كله كويس
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<ll, int> ii;
const ll INF = 1e14;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl "\n"
ll M = 1e9 + 7;
ll OO = 1e9;
const ll N=1e5+9;
ll MOD=1e9+7;
int n,m;
vector<vector<int>>anc,mx;
vector<vector<pair<int,int>>>adj;
vector<int>depth;


int Log(int x){
    return 31-__builtin_clz(x);
}

void DFS(int u,int p){
    for(auto jj : adj[u]){
      int v=jj.second;
        if(v==p)continue;
        depth[v]=depth[u]+1;
        anc[v][0]=u;
        mx[v][0]=jj.first;
        for(int i=1; i<m; i++) {
            anc[v][i] = anc[anc[v][i - 1]][i - 1];
            mx[v][i] = max(mx[v][i-1],mx[anc[v][i - 1]][i - 1]);
        }
        DFS(v,u);
    }
}

pair<int,int> k_anc(int u, int k){
    int mx2=0;
    for(int i=0; i<m; i++)
        if(k & (1<<i)) {
            mx2=max(mx2,mx[u][i]);
            u = anc[u][i];
        }
    return {u,mx2};
}

int LCA(int u, int v){
    if(depth[u]<depth[v])
        swap(u,v);
    int k=depth[u]-depth[v];
    pair<int,int> p=k_anc(u,k);
    u=p.first;
    int mx2=p.second;

    if(u==v)
        return mx2;
    for(int i=m-1; i>=0; i--){
        if(anc[u][i]!=anc[v][i]){
            mx2=max({mx2, mx[u][i], mx[v][i]});
            u=anc[u][i];
            v=anc[v][i];
        }
    }
    return max({mx2, mx[u][0], mx[v][0]});
}

int main()
{


    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

       while(cin>>n,n) {
           adj.clear();
           depth.clear();
           m = Log(n) + 1;
           adj.resize(n) ;
           depth.resize(n, 0);
           anc = vector<vector<int>>(n , vector<int>(m));
           mx = vector<vector<int>>(n, vector<int>(m));
           for (int x = 0; x <n - 1; x++) {
               int i, j, c;
               cin >> i >> j >> c;
               --i;
               --j;
               adj[i].push_back({c, j});
               adj[j].push_back({c, i});
           }
           int root = 0;
           depth[root] = 0;
           anc[root][0] = root;
           DFS(root, -1);
           int q;
           cin >> q;
           while (q--) {
               int u, v;
               cin >> u >> v;
               --u;
               --v;
               cout << LCA(u, v) << endl;
           }

       }



    return 0;
}



// int len=r-l+1;
// int ls=Log(len);
// int st=l;
// int mn=OO;
// for(int j=0; j<=ls; j++){
//     if((len>>j)&1){
//         mn=min(mn,table[st][j]);
//         st+=(1<<j);
//     }
// }
// return mn;

