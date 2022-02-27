#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main(){
 int n;
 cin>>n;
  float k[100];
  double sum=0;
 for(int i=0;i<n;i++)
 {
     cin>>k[i];
     sum+=k[i];
 }
 cout<<sum/n;


 return 0;
}