#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int n,m;
vector<string>adj;
vector<vector<bool>>vis;
int num=0;
int X[4]={1,-1,0,0};
int Y[4]={0,0,1,-1};
char l;
void dfs(int a, int b)
{
    num++;
    vis[a][b]=true;
    for(int i=0;i<4;i++)
    {
        int x=X[i]+a;
        int y=Y[i]+b;
        if(x<0||x>=n)
        {
            continue;
        }
        if(y<0)
        {
            y=m-1;
        }
        x=x%n;
        y=y%m;
        if(!vis[x][y]&&adj[x][y]==l)
        {
            dfs(x,y);
        }
    }

}


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

#endif

   while(cin>>n>>m) {
       adj.clear();
       vis.clear();
       num=0;
       adj.resize(n);
       vis.resize(n, vector<bool>(m));
       for (int i = 0; i < n; i++) {
           cin >> adj[i];
       }
       int a, b;
       cin >> a >> b;
       l = adj[a][b];
       dfs(a, b);
       int res = 0;
       for (int i = 0; i < n; i++) {
           for (int j = 0; j < m; j++) {
               if (!vis[i][j] && adj[i][j] == l) {
                   num = 0;
                   dfs(i, j);
                   res = max(res, num);
               }
           }
       }
       cout << res<<endl;

   }








    return 0;
}
