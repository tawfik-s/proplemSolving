#include<iostream>

#include <string>

using namespace std;
int main(){
    int n,count=0;
    string x;
    cin>>n;
    cin>>x;
    char last;
    for(int i=0;i<n;i++)
    {
        if(x[i]==last)
        {
            count++;
        }
        else
        {
            last=x[i];
        }
    }

    cout<<count;

       return 0;
}