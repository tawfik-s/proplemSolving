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

int n,m,k;
vector<int>v;
vector<vector<int>>memo;

int solve(int i,int rem,int rl)
{
    if(rem==0)
    {
        return 0;
    }
    if(i==n)
    {
        return -1e8;
    }
    if(memo[i][rl]!=-1)
        return memo[i][rl];

    int x=0;

      x=max(x,solve(i+1,rem-1,rl)+v[i]);

    if(rl>0&&i!=0)
    {
      x=max(x,solve(i-1,rem-1,rl-1)+v[i]);
    }

    return memo[i][rl]=x;
}

//15
//19
//150
//56

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

   int t;
   cin>>t;
   while(t--)
   {
       cin>>n>>m>>k;
       memo=vector<vector<int>>(n+3,vector<int>(k+3,-1));
       v.clear();
       v.resize(n);
       for(int i=0;i<n;i++)
       {
           cin>>v[i];
       }
       cout<<solve(0,m+1,k)<<endl;
   }


    return 0;
}