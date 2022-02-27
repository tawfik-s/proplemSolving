
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
vector<vector<int>>adj,anc;
vector<int>depth;


int Log(int x){
    return 31-__builtin_clz(x);
}

void DFS(int u, int p){
    for(int v : adj[u]){
        if(v==p) continue;
        depth[v]=depth[u]+1;
        anc[v][0]=u;
        for(int i=1; i<m; i++)
            anc[v][i]=anc[anc[v][i-1]][i-1];
        DFS(v,u);
    }
}

int k_anc(int u, int k){
    for(int i=0; i<m; i++)
        if(k & (1<<i))
            u=anc[u][i];
    return u;
}

int LCA(int u, int v){
    if(depth[u]<depth[v])
        swap(u,v);
    int k=depth[u]-depth[v];
    u=k_anc(u,k);

    if(u==v)
        return u;
    for(int i=m-1; i>=0; i--){
        if(anc[u][i]!=anc[v][i]){
            u=anc[u][i];
            v=anc[v][i];
        }
    }
    return anc[u][0];
}
int solve(int f, int s, int t){
    int sf=LCA(s,f), tf=LCA(t,f), st=LCA(s,t);
    if(sf==f && tf==f)
        return depth[st]-depth[f]+1;
    if(sf==f || tf==f)
        return 1;
    if(sf==tf)
        return depth[f]+depth[st]-2*depth[sf]+1;
    return depth[f]-max(depth[sf],depth[tf])+1;
}
int main()
{


    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    int q;
    cin>>n>>q;
    m= Log(n)+1;
    adj.resize(n);
    depth.resize(n);
    anc=vector<vector<int>>(n,vector<int>(m));
    for(int i=1;i<n ;i++)
    {
        int v;
        cin>>v;
        adj[i].push_back(--v);
        adj[v].push_back(i);

    }
    int root=0;
    depth[root]=0;
    anc[root][0]=root;
    DFS(root,-1);
    while(q--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;c--;
        cout<<max({solve(a,b,c),solve(b,a,c),solve(c,a,b)})<<"\n";
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
