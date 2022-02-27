
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

int n,a,b,c;

vector<int>v;


int solve(int r)
{
    if(r==0)
        return 0;
    if(v[r]!=-1e9)
        return v[r];
     int res=-1e9;
    if(r>=a)
    {
        res=max(res,solve(r-a)+1);
    }
    if(r>=b)
    {
        res=max(res,solve(r-b)+1);
    }
    if(r>=c)
    {
        res=max(res,solve(r-c)+1);
    }
    if(res<0)
    {
        return -1e9;
    }

    return v[r]=res;
}

// i can't solve iterative so i will solve recursive.

int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d%d%d%d",&n,&a,&b,&c);

    v.resize(n+3,-1e9);
   v[0]=0;

    for(int i=1; i<=n; i++) {
        if(i >= a) v[i] = max(v[i], v[i-a]+1);
        if(i >= b) v[i] = max(v[i], v[i-b]+1);
        if(i >= c) v[i] = max(v[i], v[i-c]+1);
    }
    int x=v[n];
    printf("%d",x);



    return 0;
}

