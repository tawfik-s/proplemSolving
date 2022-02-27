
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
vector<ll>arr;
vector<vector<ll>>table;


int Log(int x){
    return 31-__builtin_clz(x);
}


void buildTable(){
    table=vector<vector<ll>>(n,vector<ll>(Log(n)+1));
    for(int i=0; i<n; i++)
        table[i][0]=arr[i];
    for(int j=1; (1<<j)<=n; j++)
        for(int i=0; i+(1<<j)-1<n; i++)
            table[i][j]=__gcd(table[i][j-1],table[i+(1<<(j-1))][j-1]);
}


ll query(int l, int r){

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

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<ll>values(n);
        for(int i=0;i<n;i++)
        {
            cin>>values[i];
        }
        if(n==1) { cout << 1 << endl;  continue;}
        arr=vector<ll>(n-1);
        for(int i=0;i<n-1;i++)
        {
            arr[i]=abs(values[i]-values[i+1]);
        }
        n--;
        int res=1;
        buildTable();
        int l=0;
        for(int r=0;r<n;r++)
        {
            while(l<=r&&query(l,r)==1)
                l++;

            res=max(res,r-l+2);

        }
        cout<<res<<endl;


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
