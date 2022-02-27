#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;


int main(){
  int n,count=0;
  cin>>n;
  int max,min;
  deque<int>arr;
  for(int i=0;i<n;i++)
  {
      int z;
      cin>>z;
      arr.push_back(z);
  }
  min=arr[0];
  max=arr[0];
    for(int i=1;i<n;i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
            count++;
        }
        if(min>arr[i])
        {
            min=arr[i];
            count++;
        }

    }

   cout<<count;
 return 0;
}