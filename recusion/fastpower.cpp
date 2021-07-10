// Author : tawfik shalash
//link:https://codeforces.com/group/gA8A93jony/contest/269931/problem/C
//more about idea:https://cp-algorithms.com/algebra/binary-exp.html
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

ll const M=1e9+7;
ll  poww(ll x,ll z)
{

    if(z==0)
        return 1;
    ll tem=poww(x,z/2);
    tem=tem%M;
    if(z%2==1)
    {
        return (((tem*tem)%M)*x)%M;
    }
    else
    {
        return (tem*tem)%M;
    }
}

int main() {

    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    ll n,m;

    cin>>n>>m;
    n=n%M;

    cout<<poww(n,m);





    return 0;
}
