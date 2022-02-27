
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
vector<int>a,b;
vector<ll>mem;
ll solve(int i)
{
    if(i==0)
        return 1;
    if(mem[i]!=-1)
        return mem[i];
    ll x=0;
    if(i>=1) { x += solve(i - 1)%M; x=x%M;}
    if(i>=k) { x += solve(i - k)%M; x=x%M;}
    return mem[i]=x;
}


int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    cin >> t >> k;
    a.resize(t);
    b.resize(t);
    for(int i=0;i<t;i++) {
        cin >> a[i] >> b[i];
        mx=max(mx,b[i]);
    }
    mem.resize(mx+4,-1);
    solve(mx);
    mem[0]=0;
    for(int i=1;i<=mx;i++) { mem[i] += mem[i - 1]; }
    for(int i=0;i<t;i++)
    {
        cout<<(mem[b[i]]-mem[a[i]-1])%M<<endl;
    }




    return 0;
}