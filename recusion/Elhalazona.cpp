// Author : tawfik shalash
//link:https://codeforces.com/group/gA8A93jony/contest/269931/problem/J
#include <vector>
#include <list>
#include <map>
#include <math.h>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <string.h>
#include <iostream>


using namespace std;

typedef long long ll;
typedef unsigned long long ull;


int n,x=3,row=0;
vector<vector<int>>v;
vector<vector<int>>v3;
int r=1,l=1;
vector<vector<bool>>visited;
int cnt=0;
int flag=true;
int nn=0;
void  solve(int a,int b)
{
    if(!(a>0&&a<=n&&b>0&&b<=n)||visited[a][b])
    {
          nn=(nn+1)%4;
          return;
    }

   if(!visited[a][b]) {
        visited[a][b] = true;
        cnt++;
        cout << v[a][b] << " ";
        if (cnt % n == 0)
            cout << endl;
    }

   while(cnt<(n*n))
    {
        if (nn == 0) solve(a, b + 1);
        if (nn == 1) solve(a + 1, b);
        if (nn == 2) solve(a, b - 1);
        if (nn == 3) solve(a - 1, b);
    }



}





int main() {

    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

   cin>>n;
   v.resize(n+4,vector<int>(n+4,0));
    v3.resize(n+4,vector<int>(n+4,0));
   visited.resize(n+4,vector<bool>(n+4,0));

   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=n;j++)
           cin>>v[i][j];
   }


    solve(1,1);

//
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=1;j<=n;j++)
//            cout<<v3[i][j]<<" ";
//        cout<<endl;
//    }



    return 0;
}
