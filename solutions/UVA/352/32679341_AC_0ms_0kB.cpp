#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
vector<string>v;
vector<vector<bool>>vis;

int X[]={1,-1,0,0,1,-1,1,-1};
int Y[]={0,0,1,-1,1,1,-1,-1};

bool check(int x,int y)
{
    if(x>=0&&y>=0&&x<n&&y<n)
    {
        return true;
    }
    return false;
}
void dfs(int x,int y)
{
    vis[x][y]=true;
    int a,b;
    for(int i=0;i<8;i++)
    {
        a=x+X[i];
        b=y+Y[i];

        if(check(a,b)&&!vis[a][b]&&v[a][b]=='1')
        {
            dfs(a,b);
        }
    }

}



int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int count=0;
    while(cin>>n)
    {
        count++;
        v.clear();
        vis.clear();
        v.resize(n);
        vis.resize(n,vector<bool>(n,false));
        for(int i=0;i<n;i++)
            cin>>v[i];

        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j]&&v[i][j]=='1')
                {
                    res++;
                    dfs(i,j);
                }
            }
        }
        cout<<"Image number "<<count<<" contains "<<res<<" war eagles.\n";
    }





    return 0;
}