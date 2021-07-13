// Author : tawfik shalash
//link: https://codeforces.com/group/gA8A93jony/contest/270592/problem/J

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

vector<pair<int,int>>v;
int n,m;
int solve(int index,int cap,int s)
{

    if(index==n||cap==0)
    {
        return s;
    }


    if(cap>=v[index].first)
    {
       return max(solve(index+1,cap-v[index].first,s+v[index].second),solve(index+1,cap,s));
    }
    else
    {
        return solve(index+1,cap,s);
    }


}

int main() {

    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    cin>>n>>m;
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v[i]={x,y};
    }
    
    cout<<solve(0,m,0);





    return 0;
}
