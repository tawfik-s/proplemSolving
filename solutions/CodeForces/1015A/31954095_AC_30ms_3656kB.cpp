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
int a,b;
vector<int>v(m,0);
for(int j=0;j<n;j++)
{

    cin>>a>>b;

    for(int i=a-1;i<b;i++)
    {
        v[i]=1;
    }

}
vector<int>vv;
for(int i=0;i<m;i++)
{
    if(v[i]==0)
    {
        vv.push_back(i+1);
    }

}
cout<<vv.size()<<endl;

for(auto i:vv)
{
    cout<<i<<" ";
}


    return 0;
}