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


int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

   int n,m;
   cin>>n>>m;
   vector<int>v(n);
   for(int i=0;i<n;i++)
   {
       cin>>v[i];
   }
    reverse(v.begin(),v.end());
   for(int i=1;i<=n;i++)
   {
       v[i-1]=v[i-1]*i;
   }
   sort(v.begin(),v.end());
   int count=0,sum=0;
   for(int i=0;i<n;i++)
   {
       sum+=v[i];
       if(sum<=m)
       {
           count++;
           continue;
       }
       break;
   }
   cout<<count<<endl;

    return 0;



}