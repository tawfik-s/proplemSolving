// Author : tawfik shalash
//link: https://codeforces.com/group/gA8A93jony/contest/270592/problem/R

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
#define endl "\n"
set<vector<vector<int>>>myset;
int n;
bool isSafe(vector<vector<int>> board,int row,int col)
{
    for(int i=0;i<col;i++)
        if(board[row][i]==1)
            return false;
    for(int i=row,j=col;i>=0&&j>=0;i--,j--)
        if(board[i][j]==1)
            return false;
    for(int i=row,j=col;i<n&&j>=0;i++,j--)
        if(board[i][j]==1)
            return false;

        return true;
}
int cursum=0;

bool solveQueen(vector<vector<int>> board,int col,vector<vector<int>> vec,int sum)
{
    //our base case
    if(col >=n)
    {
        if(sum>cursum)
             cursum=sum;
        return true;
    }
    for(int i=0;i<n;i++)
    {
        if(isSafe(board,i,col)) {
            board[i][col] = 1;
            sum+=vec[i][col];
            if (solveQueen(board, col + 1,vec,sum))
                continue;
            sum-=vec[i][col];
            board[i][col] = 0;
        }
    }
    return false;
}


int main() {

    // ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    n=8;


    int t;
    scanf("%d",&t);
    while(t--)
    {
        vector<vector<int>>v(n,vector<int>(n,0));
        vector<vector<int>>vec(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&vec[i][j]);
            }
        }

        solveQueen(v,0,vec,0);
        printf("%d\n",cursum);
        cursum=0;
    }










    return 0;
}