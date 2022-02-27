
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

ll v[(int)1e5+5],h[(int)1e5+5];
ll memo[(int)1e5+5];
int n;
ll solve(int i,int pre)
{
    if(i==n-1) return 0;
    if(memo[i]!=-1)
    {
        return memo[i];
    }
    ll mx=0;
    if(v[i]-h[i]>pre)
        mx=max(mx,1+solve(i+1,v[i]));
    else if(v[i]+h[i]<v[i+1])
        mx=max(mx,1+solve(i+1,v[i]+h[i]));
    else
        mx=solve(i+1,v[i]);

    return memo[i]=mx;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    memset(memo, -1, sizeof memo);
    for(int i=0;i<n;i++)
    {
        cin>>v[i]>>h[i];
    }

   if (n <= 2) cout << n;
   else
    cout << solve(1, v[0]) + 2;




    return 0;
}
