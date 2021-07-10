// Author : tawfik shalash
//link:https://codeforces.com/group/gA8A93jony/contest/269931/problem/L
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


int k=0;

void solve (ll n,ll m)
{

    if(n==1)
        return;
    if(m%2==1)  // odd don't change the bit state
    {
        solve(n-1,m/2+1);
    }
    else   // even change the bit state
    {
        k=!k;
        solve(n-1,m/2);
    }

}


int main() {

    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;

        solve(n,m);

        if(k==0)
            cout<<0<<endl;
        else
            cout<<1<<endl;

        k=0;

    }




    return 0;
}
