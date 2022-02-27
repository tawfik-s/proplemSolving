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

  if(n>m)
  {
      cout<<n-m;
      return 0;
  }
  int count=0;
  queue<pair<int,int>>qu;
  qu.push({n,0});
  vector<bool>vis(1e5,false);
  while(!qu.empty())
  {
      if(vis[qu.front().first])
      {
          qu.pop();
          continue;
      }
      vis[qu.front().first]=true;
      if(qu.front().first==m)
      {
          cout<<qu.front().second;
          break;
      }
      if(qu.front().first==0)
      {
          qu.pop();
          continue;
      }
      int node=qu.front().first;
      int level=qu.front().second;
      qu.pop();

      qu.push({node-1,level+1});
      if(node<m)
      qu.push({node*2,level+1});

  }




    return 0;
}