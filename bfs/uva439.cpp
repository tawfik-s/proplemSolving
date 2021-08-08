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

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;

bool valid(int x,int y)
{
    return x<=8&&y<=8&&x>0&&y>0;
}

int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int dirx[]={2,2,-2,-2,-1,1,1,-1};
    int diry[]={-1,1,1,-1,2,2,-2,-2};

string a,b; bool flag=false;
while(cin>>a)
{
    cin>>b;
    if(a==b) {
        cout<<"To get from "<<a<<" to "<<b<<" takes "<<0<<" knight moves."<<endl;
        continue;
    }

    flag=false;
    vector<vector<int>>vis(9,vector<int>(9,-1));
    int x1=a[0]-'a'+1,y1=a[1]-'1'+1,x2=b[0]-'a'+1,y2=b[1]-'1'+1;
    queue<pair<int,int>>qu;
    qu.push({x1,y1});
    vis[x1][y1]=0;
    while(!qu.empty())
    {
        int x=qu.front().first;
        int y=qu.front().second;
        qu.pop();
        for(int i=0;i<8;i++)
        {
            int nx=x+dirx[i];
            int ny=y+diry[i];

            if(valid(nx,ny)&&vis[nx][ny]==-1)
            {
                if(nx==x2&&ny==y2)
                {
                    cout<<"To get from "<<a<<" to "<<b<<" takes "<<vis[x][y]+1<<" knight moves."<<endl;
                    flag=true;
                }
                vis[nx][ny]=vis[x][y]+1;
                qu.push({nx,ny});
            }
            if(flag)
                break;

        }
        if(flag)
            break;
    }


if(flag)
    continue;



}


    return 0;
}