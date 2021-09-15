#include<bits/stdc++.h>
using namespace std;
vector<int>par,sz;
typedef long long ll;
int findParent(int u)
{
    if(u==par[u]) return u;

    return par[u]=findParent(par[u]);
}

void join(int a,int b)
{
    a=findParent(a);
    b=findParent(b);

    if(a!=b)
    {
        if(sz[a]>sz[b])
            swap(a,b);
        par[a]=b;
        sz[b]+=sz[a];
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int n,m,cnt=0;
   while(cin>>n>>m,n||m) {
       cnt++;
       par.resize(n, 0);
       sz.resize(n, 1);
       iota(par.begin(), par.end(), 0);
       for (int i = 0; i < m; i++) {
           int u, v;
           cin >> u >> v;
           --u;
           --v;
           join(u, v);
       }
   }



    return 0;
}

































