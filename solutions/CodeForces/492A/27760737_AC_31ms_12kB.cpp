
#include <iostream>
#include <string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include <deque>
using namespace std;
int main(){
    int n,k=0,sum=0;
    cin>>n;
    while (0<=n)
    {
        if(n>=0)
            k++;
        sum=0;
      for(int i=1;i<=k;i++)
      {
          sum+=i;
      }
        n-=sum;

    }
    cout<<k-1;

    return 0;
}
