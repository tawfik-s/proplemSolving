
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

    int n,s;int number=0;
    while(cin>>n)
    {
        if(n==0)
            return 0;
       
        number++;
        cin>>s;
        --s;
        int a,b;
        vector<vector<ll>>adj(n,vector<ll>(n,-1e14));

        while(cin>>a>>b)
        {
            if(a+b==0)
                break;
            adj[--a][--b]=1;
        }
        for(int k=0;k<n;k++)
        {
            for(int u=0;u<n;u++)
            {
                for(int v=0;v<n;v++)
                {
                    adj[u][v]=max(adj[u][v],adj[u][k]+adj[k][v]);
                }
            }
        }
        ll num=0,val=0;

        for(int i=0;i<n;i++)
        {
            if(adj[s][i]!=(ll)-1e14&&adj[s][i]>val)
            {
                num=i;
                val=adj[s][i];
            }

        }
        cout<<"Case "<<number<<": The longest path from "<<
            s+1<<" has length "<<
            val<<", finishing at "<<num+1<<".\n\n";

    }


    return 0;
}

