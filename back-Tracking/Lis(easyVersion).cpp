// Author : tawfik shalash
//link: https://codeforces.com/group/gA8A93jony/contest/270592/problem/I
//Given an array, A of N integers, print the length of the longest increasing subsequence


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

ll n,m ;

vector<int>v;

int maxx=0;
void solve(int index,vector<int>rr)
{


    if(index==n)
    {

        if(rr.empty())
            return;

        if(maxx<rr.size())
            maxx=rr.size();
        return;
    }
    solve(index+1,rr);
    if(rr.empty()||v[index]>rr.back()) {
        rr.push_back(v[index]);
        solve(index + 1, rr);
    }
}


int main() {

    // ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    scanf("%d",&n);
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
    }
    vector<int>vvvv;
    solve(0,vvvv);
   cout<<maxx;




    return 0;
}