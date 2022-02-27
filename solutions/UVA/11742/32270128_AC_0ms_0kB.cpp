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

   int n,m;
   while(true)
   {
       cin>>n>>m;
       if(n==0&&m==0)
           break;
       int a[20],b[20],c[20];
       for(int j=0;j<m;j++)
           cin>>a[j]>>b[j]>>c[j];
       int p[8];
       for(int i=0;i<n;i++)
       {
           p[i]=i;
       }
       int ans=0;
       do{
           bool flag=true;
           for(int j=0;j<m&&flag;j++)
           {
               int apos=p[a[j]],bpos=p[b[j]];
               int dpos=abs(apos-bpos);
               if(c[j]>0)
                   flag=(dpos<=c[j]);
               else flag=(dpos>=abs(c[j]));
           }
           if(flag) ++ans;
       }while(next_permutation(p,p+n));
       cout<<ans<<endl;

   }




    return 0;



}
