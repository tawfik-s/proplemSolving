#include<bits/stdc++.h>

using namespace std;
typedef long long ll;



int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n,m;
    int s,t;
    vector<vector<int>>v;


    cin>>n>>m;
    v.resize(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }

    cin>>s>>t;

    queue<pair<int,int>>qu;
    vector<int>vis(n+1,0);
    qu.push({s,0});
    vis[s]=0;
    vector<vector<bool>>status;
    status.resize(n+1,vector<bool>(3,false));
    while(!qu.empty())
    {
        int node=qu.front().first;
        int vv=qu.front().second;
        vis[node]=vv;
        qu.pop();
        for(auto k:v[node])
        {
            if(!status[k][(vis[node]+1)%3])
            {
                vis[k]=vis[node]+1;
                status[k][(vis[k]%3)]=true;

                if(k==t)
                {
                    if(vis[k]%3==0) {
                        cout <<vis[k]/3;
                        return 0;
                    }

                }
                qu.push({k, vis[k]});
            }
        }
    }
    cout<<-1<<endl;






    return 0;
}