#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,m;
int bfs(vector<vector<int>>&v,int i)
{
    queue<int>qu;
    qu.push(i);
    vector<int>vis2(n+1,0);
    vis2[i]=1;
    while(!qu.empty())
    {
        int node=qu.front();
        qu.pop();
        for(auto k:v[node])
        {
            if(vis2[k]==0)
            {
                vis2[k]=vis2[node]+1;
                qu.push(k);
                if(k==n)
                {
                    return vis2[node];
                }
            }
        }
    }

    return -1;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif


    cin>>n>>m;

    vector<vector<int>>v1(n+1);
    vector<vector<int>>v2(n+1);
    vector<vector<bool>>vis(n+1,vector<bool>(n+1,false));
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        v1[a].push_back(b);
        v1[b].push_back(a);
        vis[a][b]=true;
        vis[b][a]=true;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(!vis[i][j])
            {
                v2[i].push_back(j);
            }

        }
    }
    a=bfs(v1,1);
    b=bfs(v2,1);
  //  cout<<a<<" "<<b<<endl;
    if(min(a,b)==-1)
    {
        cout<<-1;
    }
    else
    {
        cout<<max(a,b);
    }





    return 0;
}
