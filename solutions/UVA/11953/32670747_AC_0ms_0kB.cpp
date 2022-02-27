#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<string>v;
vector<vector<bool>>vis;
int n;
int X[]={1,-1,0,0};
int Y[]={0,0,1,-1};
void dfs(int x,int y)
{
    vis[x][y]=true;
    for(int i=0;i<4;i++)
    {
        int a=x+X[i];
        int b=y+Y[i];
        if(a>=0&&b>=0&&a<n&&b<n&&!vis[a][b]&&(v[a][b]=='x'||v[a][b]=='@'))
        {
            dfs(a,b);
        }
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin>>t;
    for(int w=0;w<t;w++)
    {
        cin>>n;
        v.clear();
        v.resize(n);
        vis.clear();
        vis.resize(n,vector<bool>(n,false));
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]=='x' && !vis[i][j]) {
                    res++;
                    dfs(i,j);
                }
            }
        }

        cout<<"Case "<<w+1<<": "<<res<<endl;

    }



    return 0;
}