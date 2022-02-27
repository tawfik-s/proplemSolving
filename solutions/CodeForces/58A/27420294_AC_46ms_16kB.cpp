#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main(){
     string s;
     int n=0;
     cin>>s;
     string t="hello";
     
     for(int i=0;i<s.length();i++)
     {
         if(s[i]==t[n]&&n<t.size())
         {
             n+=1;
         }
     }
     if(t.size()==n)
     {
         cout <<"YES";
     }
     else
     {
         cout<<"NO";
     }

 return 0;
}