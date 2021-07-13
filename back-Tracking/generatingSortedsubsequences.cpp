// Author : tawfik shalash
//link: https://codeforces.com/group/gA8A93jony/contest/270592/problem/G


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
vector<vector<int>>result;
// bool notSorted(vector<int>rr)
// {
//     if(rr.size()==1)
//         return false;

//     for(int i=1;i<rr.size();i++)
//     {
//         if(v[i-1]>=v[i])
//         {
//             // cout<<true<<endl;
//             return true;
//         }
//     }
//     return false;

// }
// bool arraySortedOrNot(vector<int>arr, int n)
// {

//     if (n == 1)
//         return true;

//     if (arr[n-1 ] <= arr[n - 2])
//         return false;

//     return arraySortedOrNot(arr, n - 1);
// }
void solve(int index,vector<int>rr)
{


    if(index==n)
    {
        // set<int>ss(rr.begin(),rr.end());|| !arraySortedOrNot(rr,rr.size())
        if(rr.empty())
            return;


        result.push_back(rr);
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
    sort(result.begin(),result.end());
    for(auto j:result)
    {
        for(auto i:j)
            printf("%d ",i);
        printf("\n");
    }




    return 0;
}