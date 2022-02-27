
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<deque>
using namespace std;
int main(){
    int n;
    cin>>n;
    deque <int> ar;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        for(int j=0;j<a;j++)
        {
            ar.push_back(i+1);
        }
    }
    int b;
    cin>>b;
    for(int i=0;i<b;i++)
    {
        int a;
        cin>>a;
        cout<<ar[a-1]<<endl;
    }
    return 0;
}
