#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main(){
  int n ,k; int t=240;
  cin>>n>>k;
  t=t-k;           //
int z=0;
  for(int i=1;i<n+1;i++)
  {
      z+=i*5;
      if(z-t>0)
      {
          cout<<i-1;
          return 0;
      }
      else if(z-t==0)
      {
          cout<<i;
          return 0;
      }
      else
      {
          continue;
      }

  }

   cout<<n;
}