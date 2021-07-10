// Author : tawfik shalash
//problemLink:https://codeforces.com/group/gA8A93jony/contest/269931/problem/M
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



vector<string>myset;
bool palndrom(string sub)
{
    int l=0;
    int r=sub.size()-1;
    while(r>l)
    {
        if(sub[r]!=sub[l])
            return false;
        r--;
        l++;
    }
    return true;
}
void solve (string v,int index,string sub)
{
    //reach the tree leaves go to print the leave value if sutable
    if(index==v.size()) //leaves
    {

        if(!sub.empty()&&palndrom(sub)) {
            myset.push_back(sub);
        }
    }
    else
    {
        if(!sub.empty()) {
            solve(v, v.size(), sub);
            sub += v[index];
            solve(v, index + 1, sub);
        }
        else
        {
            solve(v, index+1, sub);
            sub += v[index];
            solve(v, index + 1, sub);
        }
    }
    return;
}


int main() {

    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif


        string vv; string bb="";
        cin>>vv;
        solve(vv,0,bb);
        sort(myset.begin(),myset.end());

        for(const auto& i:myset)
        {

            cout<<i;
            cout<<endl;
        }



    return 0;
}
