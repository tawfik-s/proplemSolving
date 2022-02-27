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
vector<int>visited;
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

vector<bool>weight;
int dfs(int node,int num)
{
    visited[node]=true;
    if(num<=m&&adj[node].size()==1&&node!=1)
    {
        return 1;
    }
    else if(num>m)
    {
        return 0;
    }
    int can=0;
    for(auto k:adj[node])
    {
        if(visited[k]!=true) {
            if(weight[k])
                can+=dfs(k,num+1);
            else
                can+=dfs(k,0);

        }
    }
    return can;
}
bool connected(int node)
{
    visited[node]=true;
    for(auto k:adj[node])
    {
        // if(visited[k]!=true)
        //dfs(k);
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

    cin>>n>> m;

    adj.clear();
    visited.clear();
    adj.resize(n+1);
    visited.resize(n+1,0);
    weight.resize(n+1,0);
    for (int i = 1; i < n+1; i++)   {
        int x;
        cin>>x;
        weight[i]=x;
    }
    int a, b;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

//    displayadjList();

    cout<<dfs(1,weight[1]);

  //  displayvis();



    return 0;
}