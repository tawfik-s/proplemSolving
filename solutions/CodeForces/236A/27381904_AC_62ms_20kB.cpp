#include<iostream>
#include<string>
using namespace std;
int main(){
  string x;
  cin>>x;
  int num=0;
  for(int i=0;i<x.length();i++)
  {
      bool flag=true;
      for(int j=i+1;j<x.length();j++)
      {
          if(x[i]==x[j])
          {
              flag=false;
              continue;
          }
      }
      if(flag==true)
      num++;

  }

  if(num%2==0)
  {
      cout<<"CHAT WITH HER!";
  }
  else{
      cout<<"IGNORE HIM!";
  }

       return 0;
}