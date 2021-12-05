
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
string s1,s2;
int memo[120][120][100];
int solve(int i,int j,char last)
{
    if(i>=s1.length()||j>=s2.length())
    {
        return 0;
    }
    if(memo[i][j][last]!=-1)
    {
        return memo[i][j][last];
    }
     int x=0;
    if(s1[i]== s2[j])
    {
        x=solve(i+1,j+1,s1[i])+1;
    }
    x=max(x,solve(i+1,j,last));
    x=max(x,solve(i,j+1,last));

   return memo[i][j][last]=x;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    int cnt=1;
    while(getline(cin,s1))
    {
        if(s1=="#")
            return 0;
        getline(cin,s2);
        memset(memo,-1,sizeof memo);
        cout<<"Case #"<<cnt++<<": you can visit at most "<<solve(0,0,'#')<<" cities."<<endl;
    }



    return 0;

}