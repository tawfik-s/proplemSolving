
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


int solve(int r)
{
    if(r==n)
        return 1;
    if(r>n)
        return 0;

    int x=0;
    if(r+1<=n)
    {
        x+=solve(r+1);
    }
    if(r+5<=n)
    {
        x+=solve(r+5);
    }
    if(r+10<=n)
    {
        x+=solve(r+10);
    }
    if(r+25<=n)
    {
        x+=solve(r+25);
    }
    if(r+50<=n)
    {
        x+=solve(r+50);
    }

    return x;
}

// i can't solve iterative so i will solve recursive.

int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n=30003;
    int coins[]={1,5,10,25,50};
    vector<ll>dp(n+1,0);
    dp[0]=1;
    for(int i=0; i<5; i++)
        for(int j=0; j<=n; j++)
            if(j+coins[i]<=n)  dp[j+coins[i]]+=dp[j];
    int a;
    while(cin>>a) {
        if (dp[a] == 1)
            cout << "There is only 1 way to produce " << a << " cents change." << '\n';
        else
            cout << "There are " << dp[a] << " ways to produce " << a << " cents change." << '\n';
    }

    return 0;
}

