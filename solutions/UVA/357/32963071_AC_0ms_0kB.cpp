
/*
author: tawfik shalash
　　██░▀██████████████▀░██
　　█▌▒▒░████████████░▒▒▐█
　　█░▒▒▒░██████████░▒▒▒░█
　　▌░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▐
　　░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░
　 ███▀▀▀██▄▒▒▒▒▒▒▒▄██▀▀▀██
　 ██░░░▐█░▀█▒▒▒▒▒█▀░█▌░░░█
　 ▐▌░░░▐▄▌░▐▌▒▒▒▐▌░▐▄▌░░▐▌
　　█░░░▐█▌░░▌▒▒▒▐░░▐█▌░░█
　　▒▀▄▄▄█▄▄▄▌░▄░▐▄▄▄█▄▄▀▒
　　░░░░░░░░░░└┴┘░░░░░░░░░
　　██▄▄░░░░░░░░░░░░░░▄▄██
　　████████▒▒▒▒▒▒████████
　　█▀░░███▒▒░░▒░░▒▀██████
　　█▒░███▒▒╖░░╥░░╓▒▐█████
　　█▒░▀▀▀░░║░░║░░║░░█████
　　██▄▄▄▄▀▀┴┴╚╧╧╝╧╧╝┴┴███
　　██████████████████████


*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,a,b,c;

vector<int>v;
vector<vector<ll>>dp;
int coins[]={1,5,10,25,50};

ll solve(int r,int k)
{

    if(r==0)
        return 1;
    if(dp[r][k]!=-1)
    {
        return dp[r][k];
    }
    ll x=0;
        if(r-coins[k]>=0)
           x+=solve(r-coins[k],k);
        if(k+1<5&&r-coins[k+1]>=0) {
            x+=solve(r,k+1);
        }



    return dp[r][k]=x;
}


int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n=30003;
    dp.resize(n+1,vector<ll>(5,-1));
    solve(n,0);
    int a;
    while(cin>>a) {
        if (solve(a,0) == 1)
            cout << "There is only 1 way to produce " << a << " cents change." << '\n';
        else
            cout << "There are " << dp[a][0] << " ways to produce " << a << " cents change." << '\n';
    }



    return 0;
}
