// Author : tawfik shalash
//link: https://codeforces.com/group/gA8A93jony/contest/270592/problem/K

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
vector<int>vv;
void solve(vector<int> a, int l, int r)
{
    // Base case
    if (l == r)
        myset.insert(a);
    else
    {
        for (int i = l; i <= r; i++)
        {


            swap(a[l], a[i]);


            solve(a, l+1, r);


            swap(a[l], a[i]);  //backtrack
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
  //  scanf("%d",&m);
    //  vector<int>vv;
    vv.resize(n);
    for(int i=0;i<n;i++)
    {
        vv[i]=i+1;
    }
    solve(vv,0,n-1);
    for(auto i:myset)
    {
        for(int j=0;j<i.size();j++)
        {
            printf("%d",i[j]);
            if(j!=i.size()-1)
            {
                printf(" ");
            }

        }
        printf("\n");
    }







    return 0;
}
