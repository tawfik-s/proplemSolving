// Author : tawfik shalash
//link:https://codeforces.com/group/iLimysjd4B/contest/326525/problem/D

/*

5
S P P P P
T P T P P
T P P P P
P T E T T
P T P T T


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

int n ,a,b,x,y;
vector<vector<char>>v;
vector<vector<bool>>v2;

ll solve(int i,int j)
{
    if((!(i>0&&j>0&&i<=n&&j<=n))||v2[i][j]||v[i][j]=='T')
    {
        return 1000000;
    }


    if(v[i][j]=='E') { return 0; }

    v2[i][j]=1;

    int path1=solve(i,j-1);
    int path2=solve(i,j+1);
    int path3=solve(i-1,j);
    int path4= solve(i+1,j);

    v2[i][j]=0;
    return 1+min(min(path1,path2),min(path3,path4));



}


int main() {

    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    cin>>n;
    v.resize(n+4,vector<char>(n+4,0));
    v2.resize(n+4,vector<bool>(n+4,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>v[i][j];
            if(v[i][j]=='S')
            {
                a=i;
                b=j;
            }

        }
    }

  cout<<solve(a,b);


    return 0;
}
