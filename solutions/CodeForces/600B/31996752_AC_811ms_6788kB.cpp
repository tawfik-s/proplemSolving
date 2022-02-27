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




long long n, m;
cin>>n>>m;
vector<long long>v(n);
vector<long long>q(m);

for(int i=0;i<n;i++)
{
    cin>>v[i];
}

for(int i=0;i<m;i++)
{
    cin>>q[i];
}
sort(v.begin(),v.end());

for(int i=0;i<m;i++)
{
    int x=upper_bound(v.begin(),v.end(),q[i])-v.begin();
    
    cout<<x<<" ";
    
}



    return 0;
}





