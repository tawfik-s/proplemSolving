
/*
author: tawfik shalash

     
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
    table=vector<vector<int>>(n,vector<int>(Log(n)+1));
    for(int i=0; i<n; i++)
        table[i][0]=arr[i];
    for(int j=1; (1<<j)<=n; j++)
        for(int i=0; i+(1<<j)-1<n; i++)
            table[i][j]=max(table[i][j-1],table[i+(1<<(j-1))][j-1]);
}


int query(int l, int r){

   int j=Log(r-l+1);
   return max(table[l][j],table[r-(1<<j)+1][j]);
}

int  solveOne(int interval)
{
    int mm=1e9;
    for(int i=0; i+interval-1<n; i++)
        mm=min(mm, query(i,i+interval-1));

    return mm;
}



int main()
{


    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int q;
    cin>>n>>q;
    arr=vector<int>(n);
    for(int &x : arr) cin>>x;
    buildTable();

    while(q--){
        int in;
        cin>>in;
        cout<<solveOne(in)<<endl;
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