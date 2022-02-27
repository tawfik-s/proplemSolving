
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

    int n;
    cin>>n;
    vector<int>number(n+2,0);
    for(int i=1;i<=n;i++)
    {
        cin>>number[i];
    }
    vector<vector<int>>dp(n+2,vector<int>(n+2,0));
    for(int j=0;j<n;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(number[i]>number[j])
            {
                dp[i+1][i]=max(dp[i+1][i],dp[i][j]+1);//take
            }
            dp[i+1][j]=max(dp[i][j],dp[i+1][j]); //leave
        }
    }

    int mx=1;
    for(int i=0;i<n+1;i++)
    {
        mx=max(mx,dp[n+1][i]);
    }
    cout<<mx;


    return 0;
}

