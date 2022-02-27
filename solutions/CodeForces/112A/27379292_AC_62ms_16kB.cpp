#include<iostream>
#include<string>
using namespace std;
int main(){
   string x,y;
   cin>>x>>y;
   int r=0;

   for(int i=0;i<y.length();i++)
   {
       x[i]=toupper(x[i]);
       y[i]=toupper(y[i]);

   }
  string nx=x;
   string ny=y;

    if(nx>ny)
        cout<<1;
    else if(ny>nx)
        cout<<-1;
    else
        cout<<0;

       return 0;
}