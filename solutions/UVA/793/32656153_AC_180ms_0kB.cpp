#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<int>>adj;
vector<bool>vis;

bool dfs(int a,int b)
{
    vis[a]=true;
    if(a==b)
        return true;
    for(auto k:adj[a])
    {
        if(!vis[k])
        {
            if(dfs(k,b))return true;
        }
    }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

int t;
cin>>t;
getchar();
    int n;
    cin>>n;
while(t--)
{

    adj.clear();
    adj.resize(n+1);
    int suc=0,fai=0;
    string c;
    int a,b;
    while(cin>>c)
    {
        if(c!="c"&&c!="q")
        {
            n= stoi(c);
            break;
        }

        cin>>a>>b;
        vis.clear();
        vis.resize(n+1,false);

        if(c=="c")
        {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        else if(c=="q")
        {
            if(dfs(a,b))
                suc++;
            else
                fai++;
        }



    }

    cout<<suc<<","<<fai<<endl;

    if(t)cout<<endl;

}


    return 0;
}
