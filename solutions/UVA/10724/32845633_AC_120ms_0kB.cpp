
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

double ecdis(int ax,int ay,int bx,int by)
{
    double dx=ax-bx;
    double dy=ay-by;
    return sqrt(dx*dx+dy*dy);
}


int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif


    int n,m;
    while(cin>>n>>m,n||m)
    {
        vector<int>x(n),y(n);
        for(int i=0;i<n;i++)
            cin>>x[i]>>y[i];

        vector<vector<double>>adj(n,vector<double>(n,(1e12)));//
        vector<vector<bool>>taken(n,vector<bool>(n,0));

        for(int i=0;i<n;i++)
            adj[i][i]=0;

        while(m--)
        {
            int u,v;
            cin>>u>>v;
            --u;
            --v;
            adj[u][v]=adj[v][u]=ecdis(x[u],y[u],x[v],y[v]);
            taken[u][v]=taken[v][u]=true;
        }

        for(int k=0;k<n;k++)
            for(int u=0;u<n;u++)
                for(int v=0;v<n;v++)
                    adj[u][v]=min(adj[u][v],adj[u][k]+adj[k][v]);

                double mx=0;
                int ru=-1,rv=-1;
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<n;j++) {
                 if (taken[i][j]) continue;
                 double disij = ecdis(x[i], y[i], x[j], y[j]);
                 double sum=0;
                 for(int u=0;u<n;u++)
                 {
                     for(int v=0;v<n;v++)
                     {
                         double pre=adj[u][v];
                         double cur=
                                 min({adj[u][v],adj[u][i]+disij+adj[j][v],
                                      adj[u][j]+disij+adj[i][v]});
                         sum+=pre-cur;

                     }
                 }
                 if(sum>mx)
                 {
                     mx=sum;
                     ru=i;
                     rv=j;
                 }

             }

         }
        if(mx>0) cout<<ru+1<<' '<<rv+1<<'\n';
        else cout<<"No road required\n";

    }


    return 0;
}
