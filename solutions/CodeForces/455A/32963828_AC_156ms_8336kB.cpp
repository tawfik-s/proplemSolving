
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

vector<ll>a;
vector<ll>v;
ll n;
ll mx=0;
ll solve(int i)
{
    if(i>mx) return 0;

    if(v[i]!=-1)
        return v[i];

    ll x=0;

    x=(ll)max(x,solve(i+2)+(ll)(a[i]*i));

    x=(ll)max(x,solve(i+1));

    return v[i]=x;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    cin>>n;
    a.resize(1e5+3,0);
    v.resize(1e5+3,-1);

    for(int i=0;i<n;i++)
    {
        ll k;
        cin>>k;
        mx=max(mx,k);
        a[k]++;
    }
    cout<<solve(0);



    return 0;
}
