
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

int n,k;

vector<int>v;
int memo[10005][106];
bool solve(int i,int j)
{
    if(i==n)
    {
        if(j%k==0)
            return true;
        else
            return false;
    }
    if(memo[i][(j%k)]!=-1)
    {
        return memo[i][j%k];
    }
    return memo[i][j%k]=(solve(i+1,(j+v[i])%k)||solve(i+1,(j-v[i])%k));
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int t=0;
    cin>>t;
    while(t--) {
        memset(memo,-1,sizeof memo);
        cin >> n >> k;
        v.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        if (solve(0, 0)) {
            cout << "Divisible" << endl;
        } else {
            cout << "Not divisible" << endl;
        }
    }







    return 0;

}