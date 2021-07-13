// Author : tawfik shalash
//link:https://codeforces.com/group/gA8A93jony/contest/270592/problem/L

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

set<vector<int>>myset;
int n,m;
void solve(int index,vector<int>vv,vector<int>v)
{
    //base case

    if(v.size()==m)
    {
        myset.insert(v);
        return;
    }
    if(index==n)
    {
        return;
    }
    for(int i=0;i<vv.size();i++)
    {
      //  solve(index+1,vv,v);
        if(vv[i]==0) {
            v.push_back(i + 1);
            vv[i]=1;
            solve(index + 1, vv, v);
            vv[i]=0;
            v.pop_back();
        }
    }


}


int main() {

    // ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    scanf("%d",&n);
    scanf("%d",&m);
    vector<int>vv;
    vv.resize(n,0);
    vector<int>v4;


        solve(0,vv,v4);


    for(auto i:myset)
    {
        for(auto j:i)
            printf("%d ",j);
        printf("\n");
    }




    return 0;
}