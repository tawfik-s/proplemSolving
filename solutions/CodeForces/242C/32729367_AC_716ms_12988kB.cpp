#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
set<pair<int,int>>v;
set<pair<int,int>>vis;
map<pair<int,int>,int>dis;
int x,y,dx,dy;
int X[]={1,-1,0,0,-1,1,-1,1};
int Y[]={0,0,1,-1,1,1,-1,-1};

int bfs(int a,int b)
{
    queue<pair<int,int>>qu;
    qu.push({a,b});
    vis.insert({a,b});
    dis[{a,b}]=0;
    while(!qu.empty())
    {
        pair<int,int> pp=qu.front();
        qu.pop();
        a=pp.first;
        b=pp.second;
        if(a==dx&&b==dy)
        {
            return (dis[{a,b}]);
        }
        for(int i=0;i<8;i++)
        {
            if(vis.find({a+X[i],b+Y[i]})==vis.end()&&v.find({a+X[i],b+Y[i]})!=v.end())
            {
                dis[{a+X[i],b+Y[i]}]=dis[{a,b}]+1;
                vis.insert({a+X[i],b+Y[i]});
                qu.push({a+X[i],b+Y[i]});
            }
        }
    }
    return -1;

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>x>>y>>dx>>dy;

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int r,a,b;
        cin>>r>>a>>b;
        for(int j=a;j<=b;j++)
        {
            v.insert({r,j});
        }
    }

   cout<<bfs(x,y);



    return 0;
}