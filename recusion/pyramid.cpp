// Author : tawfik shalash
//link:https://codeforces.com/group/gA8A93jony/contest/269931/problem/E
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
vector<int>v;
int counter=0;
void  solve(int a)
{
    if(row==n)
        return ;
    else
        row++;

    for(int i=0;i<x-((a-1)/2);i++)
    {
        cout<<" ";
    }
    for(int i=0;i<a;i++)
    {
        cout<<"*";
    }

    cout<<endl;
    solve(a+2);
}





int main() {

    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    cin>>n;
    x=((2*(n-1)+1)/2);
    solve(1);





    return 0;
}
