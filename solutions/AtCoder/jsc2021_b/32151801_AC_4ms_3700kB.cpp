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



int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

int n,m;

cin>>n>>m;
set<int>res;
int x;
for(int i=0;i<n;i++)
{
    cin>>x;
    res.insert(x);
}
for(int i=0;i<m;i++)
{
    cin>>x;
    if(res.find(x)!=res.end())
    {
        res.erase(x);
    }
    else
    {
        res.insert(x);
    }
}

for(auto i:res)
{
    cout<<i<<" ";
}





    return 0;
}