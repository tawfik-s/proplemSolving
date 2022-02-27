#include<bits/stdc++.h>

using namespace std;
typedef long long ll;




int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n,m;
    vector<vector<int>>v;
    vector<int>fstate;
    vector<int>gstate;
    int odd=0;
    int even=0;
    cin>>n;
    v.resize(n);
    fstate.resize(n);
    gstate.resize(n);
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        --a; --b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        cin>>fstate[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>gstate[i];
    }

    queue<int>qu;
    vector<int>res;
    qu.push(0);
    vector<int>vis;
    vis.resize(n,0);
    vis[0]=1;
    int count=0;
    vector<pair<int,int>>status;
    status.resize(n,{0,0});
    if(fstate[0]!=gstate[0])
    {
        status[0]={0,1};
        res.push_back(0);
    }
    while(!qu.empty())
    {
        int node=qu.front();
        qu.pop();

        for(auto k:v[node])
        {
            if(vis[k]==0)
            {
                even=status[node].first;
                odd=status[node].second;
                qu.push(k);
                vis[k]=vis[node]+1;
                ///////////////////////////////////////////////////////////////////
                if(fstate[k]==gstate[k])
                {
                    if(vis[k]%2==0)
                    {
                        if(even%2!=0) {
                            even++;
                        }
                    }
                    else
                    {
                        if(odd%2!=0)
                            odd++;
                    }
                }
                else
                {
                    if(vis[k]%2==0)
                    {
                        if(even%2!=1)
                            even++;
                    }
                    else
                    {
                        if(odd%2!=1)
                            odd++;
                    }
                }
                ///////////////////////////////////////////////////////////////////
                status[k]={even,odd};
                if(even!=status[node].first||odd!=status[node].second)
                    res.push_back(k);
            }

        }

    }
     cout<<res.size()<<endl;
    for(auto k:res)
    {
        cout<<k+1<<endl;
    }








    return 0;
}