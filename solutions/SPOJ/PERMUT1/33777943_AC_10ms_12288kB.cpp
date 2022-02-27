
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

int n,k ,vid,vis[1<<13][100];
ll memo[1 << 13][100];

ll solve(int state,int inv)
{
    if((state+1)==(1<<n))
        return (inv==k);
    if(inv>k)
        return 0;
    if(vis[state][inv]==vid)
        return memo[state][inv];
    vis[state][inv]=vid;
    int off= memo[state][inv]=0;
    for(int i=0;i<n;i++)
    {
        if(!(((state)>>(i))&1)){
            memo[state][inv]+=solve(state | (1 << i), inv + off);
            ++off;
        }
    }
    return memo[state][inv];
}



int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    int t;
    cin>>t;
    for(int c=1;c<=t;++c)
    {
        cin>>n>>k;
        ++vid;
        cout<<solve(0,0)<<endl;
    }

    return 0;

}
