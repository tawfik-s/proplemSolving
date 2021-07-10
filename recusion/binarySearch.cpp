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


int n,x=3,pos=-1;
vector<int>v;

int  solve(int a,int b)
{
   int  mid=(a+b)/2;

   if(b<a)
       return -1;

   if(v[mid]==x)
       return mid+1;
   else if(v[mid]>x)
   {
       return solve(a, mid - 1);
   }
   else {
       return solve(mid + 1, b);
   }

}





int main() {

    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>x;
      cout<< solve(0,n-1)<<endl;

    }





    return 0;
}
