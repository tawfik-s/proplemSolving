#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    int r=0;
    for(int i=0;i<n;i++)
    {
         string x;
         cin>>x;
         if(x[1]=='+')
             r++;
         else
             r--;

    }
    cout<<r;
}