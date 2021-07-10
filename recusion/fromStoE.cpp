#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

//link:https://codeforces.com/group/gA8A93jony/contest/269931/problem/H

vector<vector<char>>v;
vector<vector<bool>>visited;
int n,m;
int x,y;


bool solve(int a, int b)
{
    if(!(a>0&&a<=n&&b>0&&b<=m) || visited[a][b] || v[a][b] == '*')
    {
        return false ;
    }

    if(v[a][b]=='E')
        return true;


    visited[a][b]=true;

   if( solve(a,b-1))return true;
    if(solve(a,b+1)) return true;
   if( solve(a-1,b))return true;
   if( solve(a+1,b))return true;

    return false;

}








int main ()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

#ifndef  ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif



    cin>>n>>m;

    v.resize(n+3,vector<char>(m+3,0));
    visited.resize(n+3,vector<bool>(m+3,0));

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>v[i][j];
            if(v[i][j]=='S')
            {
                x=i;
                y=j;
            }
        }


   if (solve(x,y))
       cout<<"YES";
   else
       cout<<"NO";





    return 0;
}