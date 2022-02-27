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
ll M=1e9+7;
int t, k, L = (int) 1e5,mx=0;
vector<int>a,b,ans; int c,n;
vector<vector<int>>memo;

int solve(int i,bool state)
{
    if(i==0) {
        return 0;
    }
    ll op1,op2;
    //if state=0 //come from stares
    if(memo[i][state]!=-1)
        return memo[i][state];
    if(state)
    op1=solve(i-1,1)+b[i]+0;
    else
        op1=solve(i-1,1)+b[i]+c;
    op2=solve(i-1,0)+a[i];
    return memo[i][state]=ans[i]=min(op1,op2);
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

   cin>>n>>c;
   a.resize(n);
   b.resize(n);
   ans.resize(n);
   memo.resize(n,vector<int>(2,-1));
   for(int i=1;i<n;i++)
   {
       cin>>a[i];
   }
    for(int i=1;i<n;i++)
    {
        cin>>b[i];
    }
    solve(n-1,false);
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;






    return 0;
}