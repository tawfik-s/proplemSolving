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

int n;
cin>>n;

int x;
map<int,int>mp;

for(int i=0;i<n;i++)
{
    cin>>x;
    mp[x]++;
}
int count=0;
for(auto i:mp)
{
    if(i.first==i.second)
    {
        continue;
    }
    if(i.first>i.second)
    {
        count+=i.second;
    }
    else
    {
        count+=(i.second-i.first);
    }
}

cout<<count;






    return 0;
}