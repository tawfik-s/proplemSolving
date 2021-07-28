// Author : tawfik shalash
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//

#include<bits/stdc++.h>

using namespace std;


int main()
{

#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif

vector<int>v;
int x;
while(cin>>x)
{
    v.push_back(x);
    sort(v.begin(),v.end());
    int t=v.size();
    if(t%2==0)
    {
        int x=t/2;
        cout<<(v[x]+v[x-1])/2<<endl;
    }
    else
    {
        cout<<v[t/2]<<endl;
    }
}




    return 0;
}





