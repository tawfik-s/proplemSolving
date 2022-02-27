#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<string>v;
vector<vector<bool>>vis;
int n,m;
int co=0;
int X[]={1,0,-1,0,1,-1,-1,1};
int Y[]={0,1,0,-1,1,1,-1,-1};
bool dfs(int x=0,int y=0)
{
    vis[x][y]=true;
    for(int i=0;i<2;i++)
    {
        int a=x+X[i];
        int b=y+Y[i];
        if(a>=0&&b>=0&&a<n&&b<m&&!vis[a][b]&&v[a][b]!='#')
        {
            if(a==n-1&&b==m-1)
            {
                co++;
                return true;
            }
            else
            {
                if(dfs(a,b)&&!(x==0&&y==0))
                    return true;
            }
        }
    }
    return false;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m;
    v.resize(n);
    vis.resize(n,vector<bool>(m,false));
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    dfs();
    cout<<co<<endl;






    return 0;
}