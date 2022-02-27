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
vector<string>v;vector<vector<bool>>vis;
int n,m,k;
int nu;
int q;
void dfs(int x,int y)
{
    if(min(x,y)<0||x>=n||y>=m||v[x][y]=='#'||v[x][y]=='X'||q==k||vis[x][y])
    {
        return ;
    }
    vis[x][y]=1;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
    if(q!=k)
    {
        q++;
        v[x][y]='X';
    }

}
void displayNodes()
{
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<endl;
    }

}

int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    cin>>n>>m>>k;
    v.resize(n);
    q=0;
     vis.resize(n,vector<bool>(m,false));
     bool flag=true;
     int a=0,b=0;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        if(flag)
            for(int j=0;j<m;j++)
                if(v[i][j]=='.')
                {
                    a=i;
                    b=j;
                    flag=false;
                }
    }


    dfs(a,b);
    displayNodes();
    return 0;



}