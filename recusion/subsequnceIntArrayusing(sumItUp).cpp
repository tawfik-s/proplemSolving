// Author : tawfik shalash
//link:https://codeforces.com/group/gA8A93jony/contest/269931/problem/O
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
typedef vector<int> vi;

int n,k;
set<vector<int>>myset;
void solve (vi v,int index,vi sub)
{
    //reach the tree leaves go to print the leave value if sutable
    if(index==n)
    {
        int sum=0;
        for(int i=0;i<sub.size();i++)
        {
            sum+=sub[i];
        }
        if(sum==k)
        {
            myset.insert(sub);
        }
    }
    else
    {
        solve( v,index+1,sub);
        sub.push_back(v[index]);
        solve(v,index+1,sub);
    }
    return;
}


int main() {

    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        vi vv(n); vi bb;
        for(int i=0;i<n;i++)
        {
            cin>>vv[i];
        }
        solve(vv,0,bb);

        if(myset.empty())
        {
            cout<<"NONE"<<endl;
        }
        else
        for(const auto& i:myset)
        {

            for(int j : i)
                cout<<j<<" ";

            cout<<endl;
        }
        cout<<endl;
        myset.clear();
    }




    return 0;
}
