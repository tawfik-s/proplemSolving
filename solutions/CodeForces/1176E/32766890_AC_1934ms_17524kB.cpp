#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
vector<vector<int>>v;
vector<int>vis;
void bfs(int i)
{
    queue<int>qu;
    qu.push(i);
    vis[i]=1;
    while(!qu.empty())
    {
        int node=qu.front();
        qu.pop();
        for(auto k:v[node])
        {
            if(vis[k]==0)
            {
                qu.push(k);
                vis[k]=vis[node]+1;
            }

        }
    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        v.clear();
        vis.clear();
        v.resize(n+1);
        vis.resize(n+1,0);
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            v[b].push_back(a);
            v[a].push_back(b);
        }
        bfs(1);
        set<int>odd,even;
        for(int i=1;i<vis.size();i++)
        {
            if(vis[i]%2==0)
            {
                even.insert(i);
            }
            else
            {
                odd.insert(i);
            }
        }
        if(odd.size()>even.size())
        {
            cout<<even.size()<<endl;
            for(auto eve:even)
            {
                cout<<eve<<" ";
            }

        }
        else
        {
            cout<<odd.size()<<endl;
            for(auto od:odd)
            {
                cout<<od<<" ";
            }
        }
        cout<<endl;
    }



    return 0;
}


