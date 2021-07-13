// Author : tawfik shalash
//link: https://codeforces.com/group/gA8A93jony/contest/270592/problem/Q

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
set<int>primee{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
void solve(int index,vector<int>vv,vector<int>v)
{
    //base case

    if(v.size()==n&&primee.find(v.back()+v[0])!=primee.end())
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
        if(vv[i]==0) {
            vv[i]=1;
            if(v.empty()||primee.find(v.back()+i+1)!=primee.end()) {
                v.push_back(i+1);
                solve(index + 1,vv,v);
                v.pop_back();
            }
            vv[i]=0;

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
    vector<int>vv;
    vv.resize(n,0);
    vector<int>v4;
    v4.push_back(1);
    vv[0]=1;


    solve(1,vv,v4);


    for(auto i:myset)
    {
        for(auto j:i)
            printf("%d ",j);
        printf("\n");
    }




    return 0;
}