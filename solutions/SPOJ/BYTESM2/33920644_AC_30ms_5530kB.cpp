
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

int n,m;
int v[150][150];
int memo[150][150];
int solve(int i,int j)
{
    if(i>=n||j>=m||i<0||j<0)
    {
        return 0;
    }
    if(memo[i][j]!=-1)
    {
        return memo[i][j];
    }

    int a=solve(i+1,j-1)+v[i][j];
    int b=solve(i+1,j)+v[i][j];
    int c=solve(i+1,j+1)+v[i][j];

    return memo[i][j]=max({a,b,c});
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
    while(t--){
        cin>>n>>m;
        memset(memo,-1,sizeof memo);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>v[i][j];
            }
        }
        int x=0;
        for(int j=0;j<m;j++)
        {
            x=max(x,solve(0,j));
        }
        cout<<x<<endl;


    }












    return 0;

}