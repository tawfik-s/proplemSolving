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

    int x=128, p1=1e9+7, p2=1e9+9;
    vector<ll>XP1(1e5+1),XP2(1e5+1);
    XP1[0]=XP2[0]=1;
    for(int i=1; i<=100000; i++){
        XP1[i]=(XP1[i-1]*x)%p1;
        XP2[i]=(XP2[i-1]*x)%p2;
    }

    int n;

    while(cin>>n)
    {
        string a,b;
        cin>>b>>a;
        if(a.length()<b.length())
        {
            cout<<'\n';
            continue;
        }
        ll hb=0;ll ha=0;
        for(int i=0;i<b.length();i++)
        {
            hb= pushBack(hb,x,p1,b[i]);
        }
        for(int i=0;i<b.length();i++)
        {
            ha=pushBack(ha,x,p1,a[i]);
        }
        vector<int>res;
        if(ha==hb)
        {
            res.push_back(1);
        }
        for(int i=b.length();i<a.length();i++)
        {
              ha= popFront(ha,XP1[b.length()-1],p1,a[i-b.length()]);
              ha= pushBack(ha,x,p1,a[i]);
              if(ha==hb)
              {
                  res.push_back(i-b.length()+2);
              }
        }

        if((int)res.size()==0)
        {
            cout<<"\n";
        }
        else
        {
            sort(res.begin(),res.end());
            for(auto re:res)
            {
                cout<<re-1<<"\n";
            }
        }

    }






    return 0;
}
