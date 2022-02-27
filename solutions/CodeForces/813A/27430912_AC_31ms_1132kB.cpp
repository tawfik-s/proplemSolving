#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
#include <set>
using namespace std;
bool exist(deque <int> d, int sum)
{
    for(auto d:d)
    {
        if(d==sum)
        {
            return true;
        }
    }
    return false;
}
int xbig(deque <int> d,int sum)
{
    for(auto d:d)
    {
        if(d>sum)
        {
            return d;
        }
    }
}

int main(){

    int n; long long sum=0;
    cin>>n;
    int arr[100000];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    deque<int> d;
    int m;
    cin>>m;
    if(m==0)
    {
        cout<<-1;
        return 0;
    }
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        for(int i=a;i<=b;i++) {
            d.push_back(i);
        }
    }
    if(d.back()<sum||m==0)
    {
        cout<<-1;
        return 0;
    }
    if(exist(d,sum))
    {
        cout<<sum;
    }
    else
    {
        cout<<xbig(d,sum);
    }

}











