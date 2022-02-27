
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

ll n,k;
vector<pair<int,int>>v;
ll dp[105][(int)1e5+3];
ll solve(int i,int j)
{
    if(i>=n)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    //take
    ll a=0;
    if(v[i].first+j<=k) {
        a = solve(i + 1, j + v[i].first)+v[i].second;
    }
    //leave
        a=max(a,solve(i+1,j));
    return dp[i][j]=a;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    cin>>n>>k;
    v.resize(n,{0,0});
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first>>v[i].second;
    }
    cout<<solve(0,0);





    return 0;

}