#include<iostream>
#include<cmath>

using namespace std;
int main(){
    int n,r=0,num=0;
    cin>>n>>r;
    int x= n -(n/10 )*10;
    for(int i=1;i<1000000000000;i++)
    {
        if((x*i)%10==r||(x*i)%10==0)
        {
            cout<<i;
            return 0;
        }

    }


       return 0;
}