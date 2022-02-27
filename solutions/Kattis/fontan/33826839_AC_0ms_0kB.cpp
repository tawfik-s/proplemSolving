
/*
author: tawfik shalash
─▄█▄─█▀█▀█─▄█▄
▀▀████▄█▄████▀▀
─────▀█▀█▀

*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> ii;
const ll INF = 1e14;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl "\n"
ll M = 1e9 + 7;
ll OO = 1e9;
ll MOD = 1e9 + 7;
int Max = 1e9, q;

int n,m;


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);


    cin>>n>>m;
    vector<string>grid(n);
    queue<pair<int,int>>qu;
    for(int i=0;i<n;i++)
    {
        cin >> grid[i];
        for(int j=0;j<grid[i].length();j++)
        {
            if(grid[i][j]=='V')
            {
                qu.push({i, j});
            }
        }
    }

    while(!qu.empty())
    {
        ii node=qu.front();
        qu.pop();
        if(node.first==n-1)
        {
            continue;
        }
        else{
            if(grid[node.first+1][node.second]=='.')
            {
                qu.push({node.first+1,node.second});
                grid[node.first+1][node.second]='V';
            }
            else if(grid[node.first+1][node.second]=='#')
            {
                if(node.second+1<m&&grid[node.first][node.second+1]=='.')
                {
                    qu.push({node.first,node.second+1});
                    grid[node.first][node.second+1]='V';
                }

                if(node.second-1>=0&&grid[node.first][node.second-1]=='.')
                {
                    qu.push({node.first,node.second-1});
                    grid[node.first][node.second-1]='V';
                }
            }
        }


    }
    for(int i=0;i<n;i++)
    {
        cout<<grid[i]<<endl;
    }







    return 0;

}
