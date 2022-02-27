#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
bool ifupper(string x)
{
    string t="";
    for(int i=0;i<x.length();i++ )
    {
        t+=toupper(x[i]);
    }
    if(t==x)
        return true;
    else
        return false;
}
bool ifup(string x)
{
    string t;
    t+=tolower(x[0]);
    for(int i=1;i<x.length();i++ )
    {
        t+=toupper(x[i]);
    }
    if(t==x)
        return true;
    else
        return false;
}

int main(){
   string x;
   cin>>x;
   if(ifupper(x)||ifup(x))
   {
       string t="";
       if(ifup(x))
       {
           t+=toupper(x[0]);
           for(int i=1;i<x.length();i++ )
           {
               t+=tolower(x[i]);
           }
       }
       else
       {
           for(int i=0;i<x.length();i++ )
           {
               t+=tolower(x[i]);
           }
       }

       cout<<t;

   }
   else
   {
       cout<<x;
   }

   return 0;
}