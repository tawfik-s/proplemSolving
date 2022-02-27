#include<iostream>
#include<string>
using namespace std;
int main(){
   int l,k,g[1000],z=0;
   cin>>l>>k;
   for(int i=0;i<l;i++)
   {
       cin>>g[i];

   }
   k=g[k-1];

       for(int i=0;i<l;i++)
       {
           if(g[i]==0)
               continue;
           if(g[i]>=k)
               z++;
       }

   cout<<z;

       return 0;
}