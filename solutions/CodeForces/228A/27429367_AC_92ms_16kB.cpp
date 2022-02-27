#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
#include <set>
using namespace std;


int main(){
deque <int> s;
 int arr[4];
 for(int i=0;i<4;i++)
 {
     cin>>arr[i];
 }
 for(int i=0;i<4;i++)
 {    int k=0;
     for(int j=0;j<4;j++)
     {
         if(arr[i]==arr[j])
         {
             k++;
         }
     }
     s.push_back(k);
 }

   bool flag= true;
    for(auto s:s)
    {
       if(s==2)
       {
           continue;
       }
       else flag=false;
    }
    if(flag==true) { cout << 2; return 0;}
    else
    {
        int max=0;
        for(auto s:s)
        {
            if(s>max)
            {
                max=s;
            }
        }
        cout<<max-1;

    }


}











