
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
     عك وليس كله كويس
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<ll, int> ii;
const ll INF = 1e14;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl "\n"
ll M = 1e9 + 7;
ll OO = 1e9;
const ll N=1e5+9;
ll MOD=1e9+7;


int n;
string str;
vector<vector<int>>bit;

void add(int indx, char ne, char old){
    for(int i=indx; i<=n; i+=(i & -i)){
        bit[i][old-'a']--;
        bit[i][ne-'a']++;
    }
}
void add(int indx, char ne){
    for(int i=indx; i<=n; i+=(i & -i)){
        bit[i][ne-'a']++;
    }
}

void build(){
    bit=vector<vector<int>>(n+1,vector<int>(26,0));
    for(int i=1; i<=n; i++)
        add(i, str[i - 1]);
}

vector<int> prefix(int indx){
    vector<int>ret(26,0);
    for(int i=indx; i>=1; i-=(i & -i))
        for(int j=0; j<26; j++)
            ret[j]+=bit[i][j];
    return ret;
}

int range(int l, int r){
    vector<int>sr=prefix(r);
    vector<int>sl=prefix(l-1);
    int ret=0;
    for(int i=0; i<26; i++)
        if(sr[i]-sl[i]>0)
            ret++;
    return ret;
}


int main()
{
   ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    cin >> str;
    n=str.length();
    build();
    int q;
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        if(t==1){
           int in;char ch;
            cin>>in>>ch;
            add(in, ch, str[in - 1]);
            str[in - 1]=ch;
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<range(l,r)<<'\n';
        }
    }


    return 0;
}


