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

int a;
cin>>a;
vector<int>v(a);
for(int i=0;i<a;i++)
{
    cin>>v[i];
}
sort(v.begin(),v.end());
int x=(v.size()-1)/2;

deque<int>v1(v.begin(),v.begin()+x+1);
deque<int>v2(v.begin()+x+1,v.end());
reverse(v2.begin(),v2.end());
vector<int>v3;
bool flag= true;
for(auto i=0;i<a;i++)
{
    if(flag)
        {v3.push_back(v1.front()); v1.pop_front();}
    else
       { v3.push_back(v2.front()); v2.pop_front();}
       flag=!flag;
    
}

for(auto i:v3)
{
    cout<<i<<" ";
}


    return 0;
}





