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
int n,m,q;
vector<pair<int,pair<int,int>>>edges;
vector<int>dis;
vector<int>val;
void bellman(){

    dis=vector<int>(N,INF);
    dis[1]=0;
    for(int i=1;i<=n;i++)
    {
        bool isUpdated=0;
        for(auto e:edges)
        {
            if(dis[e.second.second]>dis[e.second.first]+e.first) {
                if(dis[e.second.first]==INF)continue;
                dis[e.second.second] = dis[e.second.first] + e.first;
                isUpdated = 1;
            }
        }
        if(isUpdated==0)
            break;
    }
    for(int i=1;i<=n;i++)
    {
        bool isUpdated=0;
        for(auto e:edges)
        {
            if(dis[e.second.second]>dis[e.second.first]+e.first) {
                if(dis[e.second.first]==INF)continue;
                else dis[e.second.second]=-INF;
                isUpdated = 1;
            }
        }
        if(isUpdated==0)
            break;

    }

}
int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int num=1;

    while(cin>>n)
    {
        printf("Set #%d\n",num++);
        edges.clear();
        dis.clear();
        val.clear();

        val.resize(N);

        for(int i=1;i<=n;i++)
        {
            cin>>val[i];
        }

        cin>>m;
        for(int i=0;i<m;i++)
        {
            int a,b, c;
            cin>>a>>b;
            c=val[b]-val[a];
            c=c*c*c;
            edges.push_back({c,{a,b}});
        }
        bellman();
        cin>>q;
        for(int i=0;i<q;i++) {
            int a;
            cin>>a;
            ll ans = dis[a];
            if (ans == INF || ans < 3) {
                printf("?\n");
            } else {
                printf("%d\n",ans);
            }
        }

    }



    return 0;
}
