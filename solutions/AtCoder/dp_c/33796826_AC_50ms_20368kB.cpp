
/*
author: tawfik shalash
─▄█▄─█▀█▀█─▄█▄
▀▀████▄█▄████▀▀
─────▀█▀█▀

*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> ii;
const ll INF = 1e14;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl "\n"
ll M = 1e9 + 7;
ll OO = 1e9;
ll MOD = 1e9 + 7;
int Max = 1e9, q;

int n;

vector<vector<int>>v;
vector<vector<int>>memo;

int solve(int indx,int state)
{
    if(indx==n)
    {
        return 0;
    }
    if(memo[indx][state]!=0)
    {
        return memo[indx][state];
    }
    int ans=0;
    for(int i=0;i<3;i++)
    {
        if(i!=state)
       ans=max( solve(indx+1,i)+v[indx][i],ans)  ;
    }


    return memo[indx][state]=ans;

}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    cin>>n;
    v.resize(n+1,vector<int>(3,0));
    memo.resize(n+1,vector<int>(3,0));

    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[i][0]=a;
        v[i][1]=b;
        v[i][2]=c;
    }

    cout<<max({solve(0,0),solve(0,1),solve(0,2)});





    return 0;

}
