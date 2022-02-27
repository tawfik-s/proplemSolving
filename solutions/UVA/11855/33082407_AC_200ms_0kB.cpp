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

    string s;        int cnt=0;

    while(getline(cin,s))
    {
        if(cnt)
            cout<<endl;
        string ss="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
                ss+=s[i];
        }
        s=ss;
        int n=s.length();
        for(int i=1;i<=s.length();i++)
        {

            map<pair<int,int>,int>mp;
            int h1=0,h2=0; int mx=1;
            for(int j=0;j<i;j++)
            {
                h1= pushBack(h1,x,p1,s[j]);
                h2= pushBack(h2,x2,p2,s[j]);
            }
            mp[{h1,h2}]=1;

            for(int j=i;j<s.length();j++)
            {
                h1= popFront(h1,XP1[i-1],p1,s[j-i]);
                h1= pushBack(h1,x,p1,s[j]);
                h2= popFront(h2,XP2[i-1],p2,s[j-i]);
                h2= pushBack(h2,x2,p2,s[j]);
                mp[{h1,h2}]++;
                mx=max(mp[{h1,h2}],mx);
            }
            if(mx==1) { break;}
            cout<<mx<<endl;
        }
        cnt=1;

    }




    return 0;
}
