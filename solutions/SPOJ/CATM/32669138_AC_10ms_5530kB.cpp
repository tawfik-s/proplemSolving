#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<vector<int>>vis;
int n,m;
bool check(int a,int b)
{
    if(a<=n&&b<=m&&a>0&&b>0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int X[]={1,-1,0,0};
int Y[]={0,0,1,-1};
void bfs(int x,int y)
{
    queue<pair<int,int>>qu;
    qu.push({x, y});
    vis[x][y]=1;
    while(!qu.empty())
    {
        x=qu.front().first;
        y=qu.front().second;
        qu.pop();
        for(int i=0;i<4;i++)
        {
            int a=X[i]+x;
            int b=Y[i]+y;

            if(check(a,b)&&(vis[a][b]>vis[x][y]+1||vis[a][b]==0))
            {
                vis[a][b]=vis[x][y]+1;
                qu.push({a,b});

            }

        }

    }

}

bool mbfs(int x,int y)
{
    queue<pair<int,int>>qu;
    qu.push({x, y});
    vis[x][y]=-1;
    while(!qu.empty())
    {
        x=qu.front().first;
        y=qu.front().second;
        qu.pop();
        for(int i=0;i<4;i++)
        {
            int a=X[i]+x;
            int b=Y[i]+y;

            if(check(a,b))
            {
                if(vis[a][b]>abs(vis[x][y]-1)) {
                    vis[a][b] = vis[x][y] - 1;
                    qu.push({a,b});
                }
            }
            else
            {
                return true;
            }

        }

    }
    return false;

}



int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int x1,y1,x2,y2,x3,y3;

    cin>>n>>m;
    int k;
    cin>>k;

    while(k--)
    {
        vis.clear();
        vis.resize(n+1,vector<int>(m+1,0));

        cin>>x1>>y1>>x2>>y2>>x3>>y3;

        //bfs()for mouse  then bfs for cats
        bfs(x2,y2);
        bfs(x3,y3);
        if(mbfs(x1,y1))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

    }



    return 0;
}