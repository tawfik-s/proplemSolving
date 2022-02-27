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


   int n,k;
   cin>>n>>k;
   vector<int>v;
   vector<int>lo;
   vector<int>ol;
   int t, a,b;
   for(int i=0;i<n;i++)
   {
       cin>>t>>a>>b;
       if(a==1&&b==1)
       {
           v.push_back(t);
       }
       else if(a==1)
       {
           lo.push_back(t);
       }
       else if(b==1)
       {
           ol.push_back(t);
       }
   }
   if(v.size()+min(lo.size(),ol.size())<k)
   {
       cout<<-1;
       return 0;
   }

   sort(lo.begin(),lo.end());
   sort(ol.begin(),ol.end());

   int x=min(lo.size(),ol.size());
   for(int i=0;i<x;i++)
   {
       v.push_back(lo[i]+ol[i]);
   }
   sort(v.begin(),v.end());

   ll count=0;
   for(int i=0;i<k;i++)
   {
       count+=v[i];
   }
   cout<<count;




    return 0;

}
