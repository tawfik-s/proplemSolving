
#include <iostream>
#include <string>
#include <deque>
#include <stack>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    int n,k=0;
    cin>>n;
    while(true)
    {
       k+=n%2;
       n=n/2;
       if(n==0)
         break;
    }
    cout<<k;


    return 0;
}
