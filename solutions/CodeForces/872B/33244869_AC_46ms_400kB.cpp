
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

int n;
vector<int>arr;
vector<vector<int>>table;

int Log(int x)
{
    return 31-__builtin_clz(x);
}
void buildTable(){
    table=vector<vector<int>>(n,vector<int>(Log(n)+1));
    for(int i=0;i<n;i++)
        table[i][0]=arr[i];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=0;i+(1<<j)-1<n;i++)
        {
            table[i][j]=min(table[i][j-1],table[i+(1<<(j-1))][j-1]);
        }
}
int query(int l,int r)
{

    int j=Log(r-l+1);
    return min(table[l][j],table[r-(1<<j)+1][j]);
//    int len=r-l+1;
//    int ls=Log(len);
//    int st=1;
//    int mn=OO;
//    for(int j=0;j<=ls;j++)
//    {
//        if((len>>j)&1)
//        {
//            mn=min(mn,table[st][j]);
//            st+=(1<<j);
//        }
//    }
//    return mn;

}




int main()
{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int q;
    cin>>n>>q;
    arr=vector<int>(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    if(q==1)
    {
        int ans=arr[0];
        for(int i=0;i<n;i++)
          ans=min(arr[i],ans);
        cout<<ans;
        return 0;
    }
    if(q==2)
    {
        cout<< max(arr[0],arr[n-1]);
        return 0;
    }
    else
    {
        int ans=arr[0];
        for(int i=0;i<n;i++)
            ans=max(arr[i],ans);
        cout<<ans;
        return 0;
    }



    return 0;
}
//
//    buildTable();
//    int ans=0;
//    int l=0;
//    int j=q;
//    for(l=0;l+j<=n;l++)
//    {
//        int res=query(l,j);
//        ans=max(ans,res);
//        l=l+j;
//    }
//    l-=j;
//    ans=max(ans, query(l,n-1));
//    cout<<ans;
//
