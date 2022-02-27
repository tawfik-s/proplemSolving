
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
vector<ll>bit;

void add (int indx,int toAdd){
    for(int i=indx;i<=n;i+=(i&-i))
        bit[i]+=toAdd;
}

void build(){
    bit=vector<ll>(n+1,0);
    for(int i=1;i<=n;i++)
        add(i,arr[i]);
}
ll prefixSum(int indx)
{
    ll sum=0;
    for(int i=indx;i>=1;i-=(i&-i))
        sum+=bit[i];
    return sum;
}

ll rangeSum(int l,int r){
    return prefixSum(r)-prefixSum(l-1);
}

int main()
{
    //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
   int cnt=1;
   while(cin>>n) {
       if(n==0)
           return 0;
       if(cnt!=1)
           cout<<endl;
       cout<<"Case "<<cnt++<<":"<<endl;

       arr.resize(n+1);
       arr[0]=0;
       for (int i = 1; i <= n; i++) {
           cin >> arr[i];
       }
       build();
       string x;
       while (true) {
           cin >> x;
           if (x == "END") { break; }
           if(x=="S")
           {
               int l,r;
               cin>>l>>r;
               add(l,r-arr[l]);
               arr[l]=r;
           }
           if(x=="M")
           {
               int l,r;
               cin>>l>>r;
               cout<<rangeSum(l,r)<<endl;
           }
       }


   }


    return 0;
}


