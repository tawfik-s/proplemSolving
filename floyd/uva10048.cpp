
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


   int n,m,q;
   int number=0;
   while(cin>>n>>m>>q,n||m||q)
   {
       number++;
       if(number!=1)
           cout<<endl;
       vector<vector<ll>>adj(n,vector<ll>(n,(ll)1e14));
       for(int i=0;i<n;i++)
       {
           adj[i][i]=0;
       }
       for(int i=0;i<m;i++)
       {
           ll a,b,c;
           cin>>a>>b>>c;
           --a ,--b;
           adj[a][b]=min(adj[a][b],c);
           adj[b][a]=min(adj[b][a],c);
       }

       for(int k=0;k<n;k++)
           for(int i=0;i<n;i++)
               for(int j=0;j<n;j++)
               {
                   adj[i][j]=min(adj[i][j],max(adj[i][k],adj[k][j]));
                   adj[j][i]=min(adj[j][i],max(adj[k][i],adj[j][k]));

               }
       cout<<"Case #"<<number<<endl;
       while(q--)
       {
           int a,b;
           cin>>a>>b;
           --a,--b;
           if(adj[a][b]==(ll)1e14)
               cout<<"no path"<<endl;
               else
           cout<<adj[a][b]<<endl;
       }

   }




return 0;
}
