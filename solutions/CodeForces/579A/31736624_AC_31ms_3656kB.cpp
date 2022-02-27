// Author : tawfik shalash


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
#include <iomanip>


using namespace std;

typedef long long ll;
typedef unsigned long long ull;
int n=3;
vector<int>v;

int solve(int index,int sum)
{
    if(index==n)
    {
        return sum;
    }


        return max(solve(index+1,sum+v[index]),solve(index+1,sum*v[index]));



}

int main() {

    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif


//v.resize(n);
//for(int i=0;i<n;i++)
//{
//    cin>>v[i];
//}
//
//cout<<solve(0,0);


       int an=0;
        cin>>n;
        while(n){
            if(n&1)an++;
            n>>=1;
        }
        cout<<an;

    return 0;
}
