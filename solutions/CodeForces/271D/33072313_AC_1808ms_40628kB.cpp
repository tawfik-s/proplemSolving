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

    string a,b;
    cin>>a>>b;
    int n=a.length();
    int k;
    cin>>k;
    set<pair<int,int>>se;
    for(int i=0;i<n;i++)
    {
        int h1=0,h2=0,bad=0;
        for(int j=i;j<n;j++)
        {
            h1= pushBack(h1,x,p1,a[j]);
            h2= pushBack(h2,x2,p2,a[j]);
            if(b[a[j]-'a']=='0')
                bad++;
            if(bad>k)
                break;
            se.insert({h1,h2});
        }
    }
    cout<<se.size();




    return 0;
}
