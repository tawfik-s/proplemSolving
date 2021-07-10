// Author : tawfik shalash
//link:https://codeforces.com/group/gA8A93jony/contest/270592/problem/N

/*

3 3
5 2 4
1 3 5
9 2 7


out put

5 1 3 2 7 
5 1 3 5 7 
5 1 9 2 7 
5 2 3 2 7 
5 2 3 5 7 
5 2 4 5 7 



*/
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

int n ,m,a,b,x,y;
vector<vector<int>>v;
vector<vector<bool>>v2;
//vector<vector<int>>tempv;

vector<vector<int>>myset;

void solve(int i,int j,vector<int>tempv)
{
    if((!(i>0&&j>0&&i<=n&&j<=m))||v2[i][j])
    {
        return ;
    }

    tempv.push_back(v[i][j]);

    if(i==n&&j==m) { myset.push_back(tempv); return ; }


    v2[i][j]=1;


solve(i,j+1,tempv);

solve(i+1,j,tempv);

    v2[i][j]=0;

}


int main() {

    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    cin>>n>>m;
    v.resize(n+4,vector<int>(m+4,0));
    v2.resize(n+4,vector<bool>(m+4,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>v[i][j];
        }
    }
    vector<int>vvv;

    solve(1,1,vvv);
    sort(myset.begin(),myset.end());
    for(auto i:myset)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }


    return 0;
}