
/*
author: tawfik shalash
─▄█▄─█▀█▀█─▄█▄
▀▀████▄█▄████▀▀
─────▀█▀█▀

*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> ii;
const ll INF = 1e14;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl "\n"
ll M = 1e9 + 7;
ll OO = 1e9;
ll MOD = 1e9 + 7;
int Max = 1e9, q;
vector<pair<int, pair<int, int> > > g[300043];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    int n, m, k;
    cin>>n>>m>>k; 
    vector<int> last(n, -1);
    vector<ll> diss(n, (ll)(1e18));
    set<pair<ll, int>> mqu;
    for(int i = 0; i < m; i++)
    {
        int x, y, w;
        cin>>x>>y>>w;
        --x;
        --y;
        g[x].push_back({y, {w, i}});
        g[y].push_back({x, {w, i}});
    }
    diss[0] = 0;
    mqu.insert({0, 0});
    int cnt = 0;
    vector<int> ans;
    while(!mqu.empty() && cnt < k)
    {
        auto z = *mqu.begin();
        mqu.erase(mqu.begin());
        int k = z.second;
        if(last[k] != -1)
        {
            cnt++;
            ans.push_back(last[k]);
        }
        for(auto y : g[k])
        {
            int a = y.first;
            int b = y.second.first;
            int c = y.second.second;
            if(diss[a] > diss[k] + b)
            {
                mqu.erase({diss[a], a});
                diss[a] = diss[k] + b;
                last[a] = c;
                mqu.insert({diss[a], a});
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto x : ans) { 
        cout << x + 1 << " "; 
    }


    return 0;

}
