
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

int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n=30000;
    int coins[]={10000,1000,500,2000,5000,100,200,50,20,10,5};

    vector<ll>dp(n+1,0);
    dp[0]=1;
    for(int i=0; i<11; i++)
        for(int j=0; j<=n; j++)
            if(j+coins[i]<=n)  dp[j+coins[i]]+=dp[j];
    int a,b;
    while(true) {
        scanf("%d.%d",&a,&b);
        if(a+b==0)
            return 0;
        int c=(int)(a*100+b);
        printf("%3d.%02d%17lld\n",a,b,dp[c]);

    }


    return 0;
}
