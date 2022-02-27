#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<(23-a)*60+(60-b)<<endl;
    }


    return 0;
}