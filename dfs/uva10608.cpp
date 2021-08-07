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
int n,m;
bool flag=false;
const int MAX=1000+2;
vector<vector<int>>adj;
vector<bool>visited;
int vid=1;

bool check=true;
void dfs2(int node,int last)
{
    visited[node]=last;
    for(auto k:adj[node])
    {
        if(visited[k]==0) {

            if(last==1)
                dfs2(k,2);
            else
                dfs2(k,1);

        }
        else if(visited[k]==last)
        {
            check=false;
        }
    }
}
set<int>s;
void dfs(int node)
{
    visited[node]=true;
    s.insert(node);
    for(auto k:adj[node])
    {
        if(visited[k]!=true) { dfs(k); }
    }
}
bool connected(int node)
{
    visited[node]=true;
    for(auto k:adj[node])
    {
        if(visited[k]!=true)
            dfs(k);
    }

    for(int i=1;i<=n;i++)
    {
        if(visited[i]==false)
            return false;

    }
    return true;

}

void displayadjList(){
    int n=0;
    for(auto i:adj)
    {
        if(n==0)
        {
            n++;
        }
        else {
            cout  << n++ << " :";
            for (auto j:i) {
                cout << j << " ";

            }
            cout << endl;
        }
    }
}
void displayvis()
{
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==vid)
            cout<<i<<" :visited"<<endl;
        else
            cout<<i<<" :not visited"<<endl;
    }
}

int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int t;
    cin>>t;

    while(t--)
    {
        cin>>n>> m;

        adj.clear();
        visited.clear();
        adj.resize(n+1);
        visited.resize(n+1,0);
        int a, b;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }


        int towns=0;
        int ma=0;
        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                s.clear();
                dfs(i);
                ma=max((int)s.size(),(int)ma);
            }

        }
        cout<<ma<<endl;

    }



    return 0;
}