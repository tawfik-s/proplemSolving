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

    dis=vector<int>(N,-INF);
    dis[1]=100;
    for(int i=1;i<n;i++)
    {
        bool isUpdated=0;
        for(auto e:edges)
        {
            if(dis[e.second.second]<dis[e.second.first]+e.first) {
                if(dis[e.second.first]<=0)continue;
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
            if(dis[e.second.second]<dis[e.second.first]+e.first) {
                if(dis[e.second.first]<=0)continue;
                else dis[e.second.second]=INF;
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

    while(cin>>n && n != -1){
        edges.clear();
        dis.clear();

        for(int i=1;i<=n;i++)
        {
            int a, b, c;
            cin >> c >> b;
            while (b--) {
                cin >> a;
                edges.push_back({c,{i,a}});
            }

        }
        bellman();

            ll ans = dis[n];
            if (ans == INF || ans >0) {
                cout << "winnable"<<endl;
            } else {
                cout << "hopeless"<<endl;

            }

    }



    return 0;
}
