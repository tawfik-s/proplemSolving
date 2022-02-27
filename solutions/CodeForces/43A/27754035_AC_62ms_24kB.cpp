
#include <iostream>
#include <string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include <deque>
using namespace std;
int main(){

    int n;
    cin>>n;
    map <string,int> mp;
    deque <string> name;
    for(int i=0;i<n;i++)
    {
        string a;
        cin>>a;
        name.push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            if(name[i]==name[j])
                sum++;
        }
        mp[name[i]]=sum;
    }
    int max=0;
    for(auto k:mp)
    {
        if(k.second>max)
            max=k.second;
    }
    for(auto k:mp)
    {
        if(k.second==max)
            cout<<k.first;
    }



    return 0;
}
