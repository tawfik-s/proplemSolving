#include<iostream>
#include<string>
using namespace std;
int main(){
  string x;
  cin>>x;
  int buf=1;
  int last=x[0];
  for(int i=1;i<x.length();i++)
  {
      if(x[i]==last)
      {
          buf++;
      }else
      {
          buf=1;
          last=x[i];
      }
      if(buf>=7)
      {
          cout<<"YES";
          return 0;
      }

  }

  cout<<"NO";
       return 0;
}