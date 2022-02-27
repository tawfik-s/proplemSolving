
/*
author: tawfik shalash
─▄█▄─█▀█▀█─▄█▄
▀▀████▄█▄████▀▀
─────▀█▀█▀

*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int dp[200][200];
int r,c;
int dx[]={0,1};
int dy[]={1,0};
bool grid[200][200];
int solve(int i, int j)
{
    if(i == r - 1 && j == c - 1) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    dp[i][j]=0;
    for(int z=0;z<2;z++)
    {
        int X=dx[z]+i;
        int Y=dy[z]+j;

        if(X<r&&Y<c&&(!grid[X][Y]))
        {
            dp[i][j]+=solve(X,Y);
        }
    }
    return dp[i][j];

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
    bool flag=false;
    while(t--)
    {

        cin>>r>>c;
        memset(dp,-1,sizeof dp);
        memset(grid,false,sizeof grid);
        string s;
        getline(cin,s);
        for(int i=0;i<r;i++)
        {
            getline(cin,s);
            stringstream sin(s);
            int p,q;sin>>p;
            while(sin>>q){
                grid[p-1][q-1]=true;
            }
        }
        if(flag)
        {
            cout<<endl;
        }
        else{
            flag=true;
        }
        cout<<solve(0,0)<<endl;

    }





    return 0;

}
