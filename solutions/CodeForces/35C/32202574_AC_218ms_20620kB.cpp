// Author : tawfik shalash
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
#include<bits/stdc++.h>
//cpp 11
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
#define fast     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"

using namespace std;


int n=0,m=0;

bool test(int x,int y)
{
    return x>=1&&x<=n&&y>=1&&y<=m;
}


int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
#ifdef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int xn[4]={1,-1,0,0};
    int yn[4]={0,0,1,-1};
    cin>>n>>m;

    int q=0;
    cin>>q;
    vector<vector<int>> vis(n+5,vector<int>(m+5,-1));

    queue<pair<int,int>>qu;
    int a,b;
    for(int i=0;i<q;i++)
    {
        cin>>a>>b;
        qu.push({a,b});
        vis[a][b]=0;
    }
    int x,y;
    while(!qu.empty())
    {
         x=qu.front().first;
         y=qu.front().second;


        qu.pop();
        for(int i=0;i<4;i++)
        {
           if( test(x+xn[i],y+yn[i])&&vis[x+xn[i]][y+yn[i]]==-1)
           {
                   qu.push({x+xn[i],y+yn[i]});
                   vis[x+xn[i]][y+yn[i]]= vis[x][y]+1;
           }

        }


    }
    cout<<x<<" "<<y;

    return 0;



}