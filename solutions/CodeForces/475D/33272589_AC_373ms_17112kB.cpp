
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
vector<int>arr;
vector<vector<int>>table;


int Log(int x){
    return 31-__builtin_clz(x);
}

void buildTable(){
    table=vector<vector<int>>(n, vector<int>(Log(n)+1));
    for(int i=0; i<n; i++)
        table[i][0]=arr[i];
    for(int j=1; (1<<j)<=n; j++)
        for(int i=0; i+(1<<j)-1<n; i++)
            table[i][j]=__gcd(table[i][j-1],table[i+(1<<(j-1))][j-1]);
}

int query(int l, int r){
    int j=Log(r-l+1);
    return __gcd(table[l][j],table[r-(1<<j)+1][j]);
}

int main()
{


    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    unordered_map<int,ll>mp;
    cin>>n;
    arr=vector<int>(n);
    for(int i=0;i<n;i++)
    {
        
        cin>>arr[i];
    }
    buildTable();
    for(int i=0; i<n; i++){
        int l=i,rf=i,rs;
        while(rf < n){
            int g=query(l, rf);
            int low=rf, md, high= n - 1;
            while(high - low > 0){
                md= (low + high + 1) / 2;

                if(query(l,md)==g)
                    low=md;
                else
                    high= md - 1;
            }
            rs=high;
            mp[g]+= rs - rf + 1;
            rf= rs + 1;
        }
    }


    int q;
    cin>>q;
    while(q--)
    {
        int y;
        cin>>y;
        cout<<mp[y]<<endl;

    }






    return 0;
}



// int len=r-l+1;
// int ls=Log(len);
// int st=l;
// int mn=OO;
// for(int j=0; j<=ls; j++){
//     if((len>>j)&1){
//         mn=min(mn,table[st][j]);
//         st+=(1<<j);
//     }
// }
// return mn;
