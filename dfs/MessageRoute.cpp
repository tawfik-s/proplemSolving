
/*
author: tawfik shalash
─▄█▄─█▀█▀█─▄█▄
▀▀████▄█▄████▀▀
─────▀█▀█▀

*/

//problem link:https://cses.fi/problemset/task/1667

#include <bits/stdc++.h>

using namespace std;


//tawfik shalash

/*
بسم الله الرحمن الرحيم

*/
typedef long long ll;

int n,m;

vector<int>vis;
vector<vector<int>>adj;
int comp=0;
vector<int>parent;
void bfs()
{
    queue<int>qu;
    qu.push(1);
    vis[1]=1;
    while(!qu.empty())
    {
        int x=qu.front();
        qu.pop();
        for(auto c:adj[x])
        {
            if(vis[c]==-1)
            {
                qu.push(c);
                vis[c]=vis[x]+1;
                parent[c]=x;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    cin>>n>>m;
    parent.resize(n+1,-1);
    vis.resize(n+1,-1);
    adj.resize(n+1);

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    parent[1]=-2;
    bfs();

    if(vis[n]==-1)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }

    vector<int>rs;
    int x=n;
    while(parent[x]!=-2)
    {
        rs.push_back(x);
        x=parent[x];
    }
    rs.push_back(1);
    cout<<rs.size()<<endl;
    reverse(rs.begin(),rs.end());
    for(int i=0;i<rs.size();i++)
    {
        cout<<rs[i]<<" ";
    }



    return 0;

}

/*
author: tawfik shalash
─▄█▄─█▀█▀█─▄█▄
▀▀████▄█▄████▀▀
─────▀█▀█▀

*/


#include <bits/stdc++.h>

using namespace std;


//tawfik shalash

/*
بسم الله الرحمن الرحيم

*/
typedef long long ll;

int n,m;

vector<int>vis;
vector<vector<int>>adj;
int comp=0;
vector<int>parent;
void bfs()
{
    queue<int>qu;
    qu.push(1);
    vis[1]=1;
    while(!qu.empty())
    {
        int x=qu.front();
        qu.pop();
        for(auto c:adj[x])
        {
            if(vis[c]==-1)
            {
                qu.push(c);
                vis[c]=vis[x]+1;
                parent[c]=x;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    cin>>n>>m;
    parent.resize(n+1,-1);
    vis.resize(n+1,-1);
    adj.resize(n+1);

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    parent[1]=-2;
    bfs();

    if(vis[n]==-1)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }

    vector<int>rs;
    int x=n;
    while(parent[x]!=-2)
    {
        rs.push_back(x);
        x=parent[x];
    }
    rs.push_back(1);
    cout<<rs.size()<<endl;
    reverse(rs.begin(),rs.end());
    for(int i=0;i<rs.size();i++)
    {
        cout<<rs[i]<<" ";
    }



    return 0;

}
