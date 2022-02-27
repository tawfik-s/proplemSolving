#include<iostream>
#include<string>
using namespace std;
int main(){

    string x,r="";
    cin>>x;
    for(int i=0;i<x.length();i++)
    {
        x[i]=tolower(x[i]);
    }
    for(int i=0;i<x.length();i++)
    {
        if(x[i]=='a'||x[i]=='o'||x[i]=='y'||x[i]=='e'||x[i]=='u'||x[i]=='i')
        {

        }
        else{
            r+='.';
            r+=x[i];
        }

    }

    cout<<r;
       return 0;
}