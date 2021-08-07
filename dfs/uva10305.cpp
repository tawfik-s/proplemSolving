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

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
vector<vector<int>>v;vector<bool>vis;
vector<int>res;

int n,m;

void dfs(int node)
{
    vis[node]=true;
    if(v[node].size()==0) { res.push_back(node); return; }
    for(auto i:v[node])
    {
        if(!vis[i]) {
            dfs(i);
//            res.push_back(i);
            vis[i]=true;
        }
    }
    res.push_back(node);
}
int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif



    while(true)
    {
        res.clear();
        v.clear();
        vis.clear();
        cin>>n>>m;
        if(n==0&&m==0)
            break;
        v.resize(n+1);
        vis.resize(n+1,false);
        int a,b;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            v[a].push_back(b);
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                dfs(i);
            }
        }
        reverse(res.begin(),res.end());
        for(auto i:res)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }












    return 0;



}