
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
int M=1e9+7;

vector<vector<int>>v;


int solve(int r,char c)
{
    if(r==n) {
        if(c=='D')
            return 1;
        else
            return 0;
    }
    if(v[r][(int)(c-'A')]!=-1)
    {
        return v[r][(int)(c-'A')];
    }
    ll count=0;
    if(c!='A')
    {
        count+=solve(r+1,'A');
        count=count%M;

    }
    if(c!='B')
    {
        count+=solve(r+1,'B');
        count=count%M;

    }
    if(c!='C')
    {
        count+=solve(r+1,'C');
        count=count%M;

    }
    if(c!='D')
    {
        count+=solve(r+1,'D');
        count=count%M;
    }

    return v[r][(int)(c-'A')]= (count%M);
}

// i can't solve iterative so i will solve recursive.

int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif


    cin>>n;
    ll a=0,b=0,c=0,d=1,ca=0,cb=0,cc=0,cd=0;
    while(n--)
    {
        ca=(b+c+d)%M;
        cb=(a+c+d)%M;
        cc=(a+b+d)%M;
        cd=(a+b+c)%M;
        a=ca;
        b=cb;
        c=cc;
        d=cd;
    }
    cout<<cd;


    return 0;
}

