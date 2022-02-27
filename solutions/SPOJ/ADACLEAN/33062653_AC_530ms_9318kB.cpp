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
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef set<int> si;
typedef pair<ll,int> ii;
const ll INF=1e14;
#define fast     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"
ll M=1e9+7;

ll fixMod(ll a, ll m){
    return (a + m)%m;
}

ll pushBack(ll h, ll x, ll p, char ch){
    return (((h*x)%p)+ch)%p;
}

ll pushFront(ll h, ll xp, ll p, char ch){ // xp=XP[len]
    return (h+(xp*ch)%p)%p;
}

ll popFront(ll h, ll xp, ll p, char ch){ // xp=XP[len-1]
    return fixMod(h-((xp*ch)%p),p);
}

int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    int x=128,x2=133, p1=1e9+7, p2=1e9+9;
    vector<ll>XP1(1e5+1),XP2(1e5+1);
    XP1[0]=XP2[0]=1;
    for(int i=1; i<=100000; i++){
        XP1[i]=(XP1[i-1]*x)%p1;
        XP2[i]=(XP2[i-1]*x2)%p2;
    }

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string a;
        cin>>a;

        ll ha=0,haa=0;

        for(int i=0;i<k;i++)
        {
            ha=pushBack(ha,x,p1,a[i]);
            haa= pushBack(haa,x2,p2,a[i]);
        }
        set<pair<int,int>>se;
        se.insert({ha,haa});
        for(int i=k;i<n;i++)
        {
              ha= popFront(ha,XP1[k-1],p1,a[i-k]);
              ha= pushBack(ha,x,p1,a[i]);
              haa= popFront(haa,XP2[k-1],p2,a[i-k]);
              haa= pushBack(haa,x2,p2,a[i]);

             se.insert({ha,haa});
        }
        cout<<se.size()<<endl;


    }






    return 0;
}
