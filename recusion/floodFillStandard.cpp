#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

// problem link :https://codeforces.com/group/gA8A93jony/contest/269931/problem/G

vector<vector<char>>v;
vector<vector<bool>>visited;
int n,m;
int x,y;
ll c;

void solve(int a, int b)
{
    if(!(a>0&&a<=n&&b>0&&b<=m) || visited[a][b] || v[a][b] == '*')
    {
           return ;
    }

        c++;

        visited[a][b]=true;

        solve(a,b-1);
        solve(a,b+1);
        solve(a-1,b);
        solve(a+1,b);

}








int main ()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

#ifndef  ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    c=0;

    cin>>n>>m;

    v.resize(n+3,vector<char>(m+3,0));
    visited.resize(n+3,vector<bool>(m+3,0));

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>v[i][j];

        }

    cin>>x>>y;
        solve(x,y);
        cout<<c;




    return 0;
}