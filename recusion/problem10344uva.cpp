// Author : tawfik shalash
//link:https://codeforces.com/group/iLimysjd4B/contest/326525/problem/D

/*

3 3
5 2 4
1 3 5
9 2 7


*/
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

int nums[5];

bool solve(int index,ll op)
{
    //base  case
    if(index==5)
    {
        if(op==23)
            return true;
        else
            return false;
    }

    // transitions
    if(solve(index+1,op+nums[index])) return true;
    if(solve(index+1,op-nums[index]))return true;
    if(solve(index+1,op*nums[index]))return true;

    return false;

}

int main() {

    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    while(true) {

        bool flag = true;

        for (int i = 0; i < 5; i++) {

            cin >> nums[i];
            if (nums[i] != 0)
                flag = false;
        }
        if (flag)
            break;
        flag=false;

        sort(nums,nums+5);

        do{
            if(solve(1,nums[0]))
            {
                cout<<"Possible"<<endl;         flag=true;

                break;
            }

        } while (next_permutation(nums,nums+5));

        if(!flag)
            cout<<"Impossible"<<endl;
    }

    return 0;
}
