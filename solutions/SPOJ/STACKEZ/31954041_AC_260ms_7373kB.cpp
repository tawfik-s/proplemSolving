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


   int q;
   cin>>q;
   stack <int>st;
   while(q--)
   {
       int x;
       cin>>x;
       if(x==1)
       {
           cin>>x;
           st.push(x);
       }
       else if(x==2)
       {
           if(!st.empty())
           {
               st.pop();
           }
       }
       else
       {
           if(st.empty())
           {
               cout<<"Empty!"<<endl;
           }
           else
           {
               cout<<st.top()<<endl;
           }
       }

   }
    return 0;
}
