
#include <iostream>
#include <string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include <deque>
using namespace std;
int main(){
   int one=0 ,zero=0;
   int n;
   string s;
   cin>>n>>s;
   for(int i=0;i<s.length();i++)
   {
       if(s[i]=='0')
           zero++;
       else
           one++;
   }
   int r;
   r=one-zero;
   if(r==0)
       cout<<r;
   else if(r>0)
       cout<<r;
   else
       cout<<r*-1;


    return 0;
}
