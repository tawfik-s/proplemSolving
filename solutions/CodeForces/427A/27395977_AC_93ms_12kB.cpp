#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int main(){
    int n,r=0,num=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if (x>0)
        {
            r+=x;
        }
        else if(x==-1 && r!=0)
        {
            r--;

        }
        else if(x==-1 && r==0)
        {
            num++;
        }

    }

cout<<num;
       return 0;
}