// Author : tawfik shalash
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef set<int> si;
typedef pair<ll,ll> ii;
const ll INF=1e14;
#define fast     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"
int n,m,q;
vector<pair<int,pair<int,int>>>edges;

ll bellman(){

    vector<ll>dis(n,0);
    bool hasCycle=0;
    for(int i=1;i<=n;i++)
    {
        bool isUpdated=0;
        for(auto e:edges)
        {
            if(dis[e.second.second]>dis[e.second.first]+e.first) {
                dis[e.second.second] = dis[e.second.first] + e.first;
                isUpdated = 1;
            }
        }
        if(isUpdated==0)
            break;
        else if(i==n)
            hasCycle=1;
    }
    if(hasCycle==1)
        return -INF;
    ll mn=INF;
    for(int i=0;i<n;i++)
        mn=min(mn,dis[i]);

    return mn;


}
int main() {

    fast
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    int t;
    cin>>t;
    while(t--)
    {
        edges.clear();
        cin>>n>>m;
        ll mn=INF;
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            --a;
            --b;
            edges.push_back({c,{a,b}});
            mn=min((ll)c,mn);
        }
        ll ans=bellman();
        if(ans==-INF)
        {
            cout<<"-inf"<<endl;
        }
        else if(ans<0)
        {
            cout<<ans<<endl;
        }
        else
        {
            cout<<mn<<endl;
        }
    }



    return 0;
}


