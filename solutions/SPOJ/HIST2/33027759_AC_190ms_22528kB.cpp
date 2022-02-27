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
int n;
vector<int>v;
vector<vector<pair<int,ll>>>mem;
pair<int,ll>solve(int ls,int mask)
{
    if(mask==(1<<n)-1) return {v[ls],1};
    if(mem[ls][mask].first!=-1)
    {
        return mem[ls][mask];
    }
    pair<int,ll>ret={-1e14,0};
    for(int i=0; i < n; i++){
        if((mask >> i) & 1) continue;
        auto op=solve(i, mask | 1 << i);
        op.first+=abs(v[i] - v[ls]);
        if(op.first>ret.first)
            ret=op;
        else if(op.first==ret.first)
            ret.second+=op.second;
    }
    return mem[ls][mask]=ret;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while(cin>>n,n)
    {
        v=vector<int>(n+1);
        for(int i=0;i<n;i++) 
        { 
            cin >> v[i]; 
        }
        mem=vector<vector<pair<int,ll>>>(n+3,vector<pair<int,ll>>(1<<n,{-1,-1}));
        v[n]=0;
        pair<int,ll> sol=solve(n,0);
        cout<<sol.first+2*n<<' '<<sol.second<<'\n';
    }




    return 0;
}