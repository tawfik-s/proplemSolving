// Author : tawfik shalash
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
#include<bits/stdc++.h>
//cpp 11
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
#define fast     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;

class compare{
    public:
    bool operator() (int a,int b)   // this function used to reverse the elements sort in an array
    {
        return a>b;
    }
};

int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

// first pair

pair<string,int> tawfeekMath;

tawfeekMath.first="kafafi";
tawfeekMath.second=7;

cout<<tawfeekMath.first<<" "<<tawfeekMath.second<<endl;

//second tuple

tuple <string ,char,int> tup;
tup=make_tuple("tawfik",'a',85.5);

cout<<get<0>(tup)<<" "<<get<1>(tup)<<" "<<get<2>(tup)<<endl;

priority_queue<int,vector<int>,compare>pq;   // used to make the smaller element with high priority

pq.push(1);
pq.push(2);
pq.push(5);
pq.push(3);
pq.push(5);
while(!pq.empty())
   {

       cout<<pq.top()<<" ";
       pq.pop();
   }

    cout<<endl;


// set

set<int>Set;
Set.insert(1);
Set.insert(2);
Set.insert(5);
Set.insert(4);
Set.insert(3);

Set.erase(2);
cout<<endl;

auto it=Set.upper_bound(4);
if(it!=Set.end())
cout<<*Set.upper_bound(8)<<endl;  // we have lower bound and find too
else
cout<<-1<<endl;
for(auto i:Set)
cout<<i<<" ";

cout<<endl;


//next multi set multiSet<int> 

multiset<int>ms;
ms.insert(1);
ms.insert(2);
ms.insert(5);
ms.insert(4);
ms.insert(3);
ms.insert(1);
ms.insert(2);
ms.insert(5);
ms.insert(4);
ms.insert(3);
ms.erase(ms.find(1));

for(auto i:ms)
cout<<i<<" ";

cout<<endl;

ms.erase(1);

for(auto i:ms)
cout<<i<<" ";

cout<<endl;


    return 0;
}