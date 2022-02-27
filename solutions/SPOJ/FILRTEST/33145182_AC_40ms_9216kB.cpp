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
typedef vector<int> vi;
typedef set<int> si;
typedef pair<ll, int> ii;
const ll INF = 1e14;
#define fast     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"
ll M = 1e9 + 7;

ll fixMod(ll a, ll m) {
    return (a + m) % m;
}

ll pushBack(ll h, ll x, ll p, char ch) {
    return (((h * x) % p) + ch) % p;
}

ll pushFront(ll h, ll xp, ll p, char ch) { // xp=XP[len]
    return (h + (xp * ch) % p) % p;
}

ll popFront(ll h, ll xp, ll p, char ch) { // xp=XP[len-1]
    return fixMod(h - ((xp * ch) % p), p);
}

//kmp
vector<int> prefix;

void buildprefix(string s, int n) {
    prefix = vector<int>(n);
    int border = 0;
    for (int i = 1; i < n; i++) {
        while (border > 0 && s[i] != s[border]) {
            border = prefix[border - 1];
        }
        if (s[i] == s[border])border++;
        prefix[i] = border;
    }

}

vector<int> Z;

void buildZ(string s, int n) {
    Z = vector<int>(n);
    int l = 0, r = 0;
    Z[0] = 0;
    for (int i = 1; i < n; i++) {
        int k = i - l;
        if (i >= r || i + Z[k] >= r) {
            l = i;
            r = max(r, i);
            while (r < n && s[r - l] == s[r]) r++;
            Z[i] = r - l;
        } else
            Z[i] = Z[k];
    }
}

int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif


    int k;string s;
    while(cin>>k>>s)
    {
        if(k==-1&&s=="*")
        {
            return 0;
        }
        if((int)s.length()>k)
        {
            cout<<0<<endl;
            continue;
        }
        int n=s.length();
        buildprefix(s,n);
        int x=prefix.back();
        string front=s.substr(0,x);
        string back=s.substr(x,n);
        k=k-(int)front.length();
        k=k/(int)back.length();
        cout<<k<<endl;

    }


    return 0;
}






//    int x=128,x2=133, p1=1e9+7, p2=1e9+9;
//    vector<ll>XP1(1e5+1),XP2(1e5+1);
//    XP1[0]=XP2[0]=1;
//    for(int i=1; i<=100000; i++){
//        XP1[i]=(XP1[i-1]*x)%p1;
//        XP2[i]=(XP2[i-1]*x2)%p2;
//    }
