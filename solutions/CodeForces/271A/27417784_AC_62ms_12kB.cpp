#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(true)
    {
        n++;
        int a,b,c,d;
        a=n%10;
        b=(n/10)%10;
        c=(n/100)%10;
        d=n/1000;
        if(d!=a&&d!=b&&d!=c&&c!=a&&c!=b&&b!=a)
        {
            cout <<d<<c<<b<<a;
            break;
        }


    }

    return 0;
}