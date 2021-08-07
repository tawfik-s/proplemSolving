// Author : tawfik shalash
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//

#include<bits/stdc++.h>

using namespace std;
#define fast     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define  endl "\n"
map<string,int>mp;
int n,k;
vector<vector<int>>v;
vector<bool>vis;


int dfs(int node)
{

    if(vis[node])
    {
        return 0;
    }
    vis[node]=true;
    int sum=1;
    for(auto i:v[node])
    {
        if(!vis[i]) { sum+=dfs(i); }
    }
    return sum;

}

int main()
{
  // fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif


    while(true) {
       scanf("%d",&n);
       scanf("%d",&k);
        v.clear();
        vis.clear();
        v.resize(n+1);
        vis.resize(n+1,false);
        if (n == 0 && k == 0)
            return 0;
        string s;
        for (int i = 0; i < n; i++) {
            cin >> s;
            mp[s] = i + 1;
        }
        for (int i = 0; i < k; i++)
        {
            string ss;
            cin>>s>>ss;
            v[mp[s]].push_back(mp[ss]);
            v[mp[ss]].push_back(mp[s]);
        }
        int maxx=0;
        for(int i=1;i<=n;i++)
        {
             if(!vis[i])
             {
                 int z=dfs(i);
                 if(z>maxx)
                     maxx=z;
             }
        }
        printf("%d\n",maxx);

        scanf("\n");
    }





    return 0;
}





