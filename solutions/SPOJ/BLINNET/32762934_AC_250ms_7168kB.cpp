#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<pair<int,pair<int,int>>>edge;
vector<int>par,sz;
ll ret=0;
int n,m;



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

void kruskal(){
    sort(edge.begin(),edge.end());
    iota(par.begin(),par.end(),0);

    for(auto e:edge)
    {
        int u=e.second.first;
        int v=e.second.second;
        int c=e.first;

        if(findParent(u)!= findParent(v))
        {
            ret+=c;
            join(u,v);
        }
    }

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    int tt;
    cin>>tt;
    while(tt--) {
        cin >> n;
        edge.clear();
        par.resize(n, 0);
        sz.resize(n, 1);
        ret = 0;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                int a, b;
                cin >> a >> b;
                --a;
                edge.push_back({b, {i, a}});
            }

        }
        kruskal();
        cout << ret<<endl;
    }
    return 0;
}

