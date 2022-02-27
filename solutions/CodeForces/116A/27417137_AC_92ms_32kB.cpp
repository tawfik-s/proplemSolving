#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int main(){
    deque<int>d;
    int n, e=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        e-=a;
        e+=b;
        d.push_back(e);
    }
    int max=0;
    for(int i=0;i<d.size();i++)
    {
        if (max<d[i])
            max=d[i];
    }
    cout<<max;






    return 0;
}