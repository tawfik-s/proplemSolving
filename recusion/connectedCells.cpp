#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

// link:https://codeforces.com/group/gA8A93jony/contest/269931/problem/I

vector<vector<char>>v;
vector<vector<bool>>visited;
int n,m;
int x,y;


void solve(int a, int b,char ch)
{
    if(!(a>0&&a<=n&&b>0&&b<=m) || visited[a][b] || v[a][b] != ch)
    {
        return ;
    }

    visited[a][b]=true;

    solve(a,b-1,ch);
    solve(a,b+1,ch);
    solve(a-1,b,ch);
    solve(a+1,b,ch);

}








int main ()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

#ifndef  ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

   int count=0;

    cin>>n>>m;

    v.resize(n+3,vector<char>(m+3,0));
    visited.resize(n+3,vector<bool>(m+3,0));

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>v[i][j];

        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(!visited[i][j]) {

                count++;
                solve(i,j,v[i][j]);

            }
        }
            cout<<count;




    return 0;
}