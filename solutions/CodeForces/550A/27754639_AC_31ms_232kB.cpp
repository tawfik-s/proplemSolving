
#include <iostream>
#include <string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include <deque>
using namespace std;
int main(){

   string s;
   cin>>s;
   bool flagA=false,flagB=false,flagAB=false;
   for(int i=0;i<s.length();i++)
   {
       if(i<s.length()-3) {
           if (((s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'A') ||
                (s[i] == 'B' && s[i + 1] == 'A' && s[i + 2] == 'B')) && !flagAB) {
               flagAB = true;
               i += 3;

           }
       }
       if(s[i]=='B'&&i!=s.length()-1&&!flagB)
       {
           //if(s[i+1]=='A'&&s[i+2]=='B') { flagAB = true;i+=2;}
          // else
               if(s[i+1]=='A') { flagB = true; i++;}

       }
       else if(s[i]=='A'&&i!=s.length()-1&&!flagA)
       {
         //  if(s[i+1]=='B'&&s[i+2]=='A') { flagAB = true;i+=2;}
           //else
               if(s[i+1]=='B') { flagA = true;i++; }


       }

   }

   if((flagA&&flagB)||((flagA||flagB)&&flagAB))
       cout<<"YES";
   else
       cout<<"NO";


    return 0;
}
