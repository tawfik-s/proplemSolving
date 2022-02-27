// Author : tawfik shalash
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
#include<bits/stdc++.h>
//cpp 11
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
#define fast     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"

using namespace std;


int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif


    int n;
    cin>>n;
    map<long long,vector<long long>>mp;
    map<long long,long long>m;
    ll a,b;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    long long xx;
    for(auto i: mp)
    {
        if(i.second.size()==1)
        {
            xx=i.first;
            break;
        }
    }
    queue<long long> qu;

    qu.push(xx);
    while(!qu.empty())
    {
        long long node=qu.front();
        qu.pop();
        m[node]=1;
        cout<<node<<" ";
        for(auto i:mp[node])
        {
            if(m[i]!=1)
            {
                qu.push(i);
            }
        }

    }


    return 0;



}