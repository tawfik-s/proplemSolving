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
int final;
ll data[(int) 1e5 + 20];
int n;
ll memo[(int)1e5 + 20];
ll solve(ll i)
{
    if(i>final)
    {
        return 0;
    }

    if(memo[i]!=-1)
    {
        return memo[i];
    }

    ll x=max(solve(i+1),(solve(i+2)+(data[i]*i))) ;
    return memo[i]=x;
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    cin >> n;
    memset(data, 0, sizeof data);
    memset(memo, -1, sizeof memo);
    int arr[100005];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        data[arr[i]]++;
    }
    final= *max_element(arr,arr+n);
    cout<<solve(0);



    return 0;

}