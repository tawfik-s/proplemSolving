
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
vector<int>mp;
int solve(int indx)
{
    if(indx>=n-1)
    {
        return 0;
    }
    if(mp[indx]!=-1)
    {
        return mp[indx];
    }

    int  ans=abs(v[indx] - v[indx + 1]) + solve(indx + 1);
    for(int i=2;i<=k&&(i+indx)<n;i++) {
        if (indx + i < n)
            ans = min(ans,abs(v[indx] - v[indx + i]) + solve(indx + i));
        else break;
    }

    return mp[indx]=ans;

}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    cin>>n>>k;
    v.resize(n);
    mp.resize(n+1,-1);

    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    cout<<solve(0);






    return 0;

}