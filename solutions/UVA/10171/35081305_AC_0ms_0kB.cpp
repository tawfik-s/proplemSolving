#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF=1e9;

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

   int n;
   while(cin>>n,n)
   {
       vector<vector<int>>adjy(300,vector<int>(300,INF));
       vector<vector<int>>adjm(300,vector<int>(300,INF));
       for(int i=0;i<300;i++)
       {
           adjy[i][i]=0;
           adjm[i][i]=0;
       }
       for(int i=0;i<n;i++)
       {
           char a,b,c,d;
           int x;
           cin>>a>>b>>c>>d>>x;

           if(a=='Y')
           {
               adjy[c][d]=x;
               if(b=='B')
                   adjy[d][c]=x;

           }
           else if(a=='M')
           {
               adjm[c][d]=x;
               if(b=='B')
                   adjm[d][c]=x;
           }

       }

       char y,m;

       cin>>y>>m;



       for (int k = 'A'; k <= 'Z'; ++k) {
           for (int i = 'A'; i <= 'Z'; ++i) {
               for (int j = 'A'; j <= 'Z'; ++j) {
                   if(adjy[i][k]<INF&&adjy[k][j]<INF) {
                       adjy[i][j] = min(adjy[i][j], adjy[i][k] + adjy[k][j]);
                   }
                   if(adjm[i][k]<INF&&adjm[k][j]<INF) {
                       adjm[i][j] = min(adjm[i][j], adjm[i][k] + adjm[k][j]);
                   }
               }
           }
       }


       pair<int,set<char>> mm={INF,{}};
       for(char i='A';i<='Z';i++)
       {
           if(adjy[y][i]+adjm[m][i]==mm.first)
           {
               mm.second.insert(i);
           }
           else
           if(adjy[y][i]+adjm[m][i]<mm.first)
           {
               mm.first=adjy[y][i]+adjm[m][i];
               mm.second.clear();
               mm.second.insert(i);
           }

       }



           if(y==m)
           {
               if(mm.first==0)
                  mm.second.insert(y);
               else
               {
                   mm.second.clear();
                   mm.first=0;
                   mm.second.insert(y);
               }
           }

       if(mm.first==INF)
           cout<<"You will never meet.\n";
       else{
           cout<<mm.first;

           for(auto i:mm.second)
           {
               cout<<" "<<i;
           }
           cout<<endl;
       }


   }






    return 0;
}