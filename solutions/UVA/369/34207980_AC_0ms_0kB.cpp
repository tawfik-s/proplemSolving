
/*
author: tawfik shalash
─▄█▄─█▀█▀█─▄█▄
▀▀████▄█▄████▀▀
─────▀█▀█▀

*/


#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


//tawfik shalash

/*
بسم الله الرحمن الرحيم

*/
ll factorial(ll n){
    if(n<=0)
        return 1;
    return n*factorial(n-1);
}
long long dp[101][101];
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll n,m;

    dp[1][1] = 1;
    dp[1][0] = 1;

    for (int i = 2; i <= 100; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }

    while(cin>>n>>m,(n)||(m)) {
       cout<< n<<" things taken "<<m<<" at a time is "<<dp[n][m]<<" exactly.\n";
   }






}
