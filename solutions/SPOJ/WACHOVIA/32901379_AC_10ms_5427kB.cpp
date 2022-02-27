
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

    while(n--)
    {
        int k,m;
        cin>>k>>m;
        vector<int>w(m),v(m);
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            w[i]=a;
            v[i]=b;
        }
         vector<vector<int>>dp(m+1,vector<int>(k+1,0));
        for(int i=0;i<m;i++)
            for(int j=0;j<=k;j++)
            {
                if(j+w[i]<=k)
                {
                    dp[i+1][j+w[i]]=max(dp[i][j]+v[i],dp[i+1][j+w[i]]);   //take
                }

                dp[i+1][j]=max(dp[i][j],dp[i+1][j]);  //leave

            }

        cout<<"Hey stupid robber, you can get "<<dp[m][k]<<".\n";

    }


    return 0;
}

