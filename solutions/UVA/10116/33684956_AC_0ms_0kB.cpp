
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
ll MOD=1e9+7;
int Max=1e9,q;

int x,y,s;
vector<vector<char>>grid;
vector<vector<int>>visit;

bool check(int X,int Y)
{
    if(X==0||x<X||y<Y||Y==0)
    {
        return true;
    }
    else
        return false;
}

void solve(int a,int b,int dis)
{
    if(check(a,b))
    {
        cout<<dis<<" step(s) to exit"<<endl;
        return;
    }

    if(visit[a][b]!=0)
    {
        cout<<visit[a][b]-1<<" step(s) before a loop of "<<dis-visit[a][b]+1<<" step(s)"<<endl;
        return;
    }
    visit[a][b]=dis+1;
    if(grid[a][b]=='N')
    {
        solve(a-1,b,dis+1);
    }
    else if(grid[a][b]=='S')
    {
        solve(a+1,b,dis+1);
    }
    else if(grid[a][b]=='W')
    {
        solve(a,b-1,dis+1);
    }
    else if(grid[a][b]=='E')
    {
        solve(a,b+1,dis+1);
    }

}


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    while(cin>>x>>y>>s)
    {
        if(x==0&&y==0&&s==0)
        {
            return 0;
        }
        grid=vector<vector<char>>(x+1,vector<char>(y+1));
        visit=vector<vector<int>>(x+1,vector<int>(y+1,0));
        for(int i=0;i<x;i++)
        {
            string s;
            cin>>s;
            for(int j=1;j<=y;j++)
            {
                grid[i+1][j]=s[j-1];
            }
        }
        solve(1,s,0);



    }




    return 0;
}

