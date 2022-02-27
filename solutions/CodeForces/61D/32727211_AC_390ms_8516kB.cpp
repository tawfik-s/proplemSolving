#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int n,m,co=0;
vector<vector<pair<int,int>>>v;
vector<ll>vis;
vector<bool>vis2;
ll sum=0;

void dfs(int i)
{
    co++;
    vis[i]=true;
    for(auto k:v[i])
    {
        if(!vis[k.first])
        {
            sum+=k.second;
            dfs(k.first);
            if(co!=n)
                sum+=k.second;
        }
    }
}

void bfs(int i=1)
{
   queue<int>qu;
   qu.push(i);
   vis[i]=-1;
    vis2[i]=true;
    while(!qu.empty())
   {
       int node=qu.front();
       qu.pop();
       for(auto k:v[node])
       {
           if(vis[k.first]==0&&!vis2[k.first])
           {
               vis2[k.first]=true;
               sum+=(k.second*2);
               if(vis[node]==-1)
                   vis[k.first]=k.second+vis[node]+1;
               else
                   vis[k.first]=k.second+vis[node];

               qu.push(k.first);
           }
       }
   }


}


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    cin>>n;
    v.resize(n+1);
    vis.resize(n+1,0);
    vis2.resize(n+1,false);
    for(int i=0;i<n-1;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        v[x].push_back({y,z});
        v[y].push_back({x,z});
    }

    bfs(1);

    if(sum!=0)
        sum=sum-*max_element(vis.begin(), vis.end());

    cout<<sum;



    return 0;
}