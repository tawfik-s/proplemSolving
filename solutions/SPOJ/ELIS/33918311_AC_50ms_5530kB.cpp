
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

int n;
vector<int>v;
int memo[100][100];
int solve(int i,int j)
{
    if(i==n)
    {
        return 0;
    }
    if(memo[i][j]!=-1)
    {
        return memo[i][j];
    }
    //take
    int x=0;
    if(v[i]>j)
       x=solve(i+1,v[i])+1;

    //leave
    int y=0;
    y=solve(i+1,j);

    return memo[i][j]=max(x,y);
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    cin>>n;
    memset(memo,-1,sizeof memo);
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    cout<<solve(0,0);











    return 0;

}