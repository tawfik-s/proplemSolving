
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

int nu=0;
while(true)
{
    bool flag=false;
    nu++;
    vector<vector<ll>>adj(105,vector<ll>(105,1e14));
    int a,b;
    for(int i=0;i<101;i++)
        adj[i][i]=0;
    while(cin>>a>>b)
    {
        if(!(a||b))
        {
            if(!flag)
            {
                return 0;
            }
            else
                break;

        }
        --a;--b;
        adj[a][b]=1;
        flag=true;

    }
    for(int k=0;k<101;k++)
        for(int u=0;u<101;u++)
            for(int v=0;v<101;v++)
            {
                adj[u][v]=min(adj[u][v],adj[u][k]+adj[k][v]);
            }
    ll sum=0;ll num=0;
    for(int u=0;u<101;u++)
        for(int v=0;v<101;v++)
        {
            if(adj[u][v]<1e14&&adj[u][v]!=0) {
                sum += adj[u][v];
                num++;
            }
        }


    cout<< "Case "<<nu<<
    ": average length between pages = "<<fixed<<setprecision(3)<<(double)sum/num<<" clicks\n";



}


    return 0;
}