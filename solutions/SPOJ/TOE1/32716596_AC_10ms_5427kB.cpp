#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<string>g(3);

bool check(string grid[])
{
    for(int i=0;i<3;i++)
    {
        if(grid[i][0]=='X'&&grid[i][1]=='X'&&grid[i][2]=='X')
            return true;
        if(grid[i][0]=='O'&&grid[i][1]=='O'&&grid[i][2]=='O')
            return true;
    }
    for(int i=0;i<3;i++)
    {
        if(grid[0][i]=='X'&&grid[1][i]=='X'&&grid[2][i]=='X')
            return true;
        if(grid[0][i]=='O'&&grid[1][i]=='O'&&grid[2][i]=='O')
            return true;
    }

    if((grid[0][0]=='X'&&grid[1][1]=='X'&&grid[2][2]=='X')
       ||(grid[0][0]=='O'&&grid[1][1]=='O'&&grid[2][2]=='O'))
        return true;
    if((grid[0][2]=='X'&&grid[1][1]=='X'&&grid[2][0]=='X')
       ||(grid[0][2]=='O'&&grid[1][1]=='O'&&grid[2][0]=='O'))
        return true;

    return false;
}
bool fflag=false;
void dfs(string grid[],bool flag=true)
{
    for(int i=0;i<3;i++) {
        for (int j = 0; j < 3; j++) {

            if (grid[i][j] != '.') {
                continue;
            }
            if (flag && g[i][j] == 'X') {
                grid[i][j] = 'X';
                if (check(grid)) {
                    if (grid[0] == g[0] && grid[1] == g[1] && grid[2] == g[2]) {
                        fflag = true;
                        return;
                    }
                } else {
                    if (grid[0] == g[0] && grid[1] == g[1] && grid[2] == g[2]) {
                        fflag = true;
                        return;
                    } else {
                        dfs(grid, !flag);
                    }
                }
            } else if (g[i][j] == 'O' && !flag) {
                grid[i][j] = 'O';
                if (check(grid)) {
                    if (grid[0] == g[0] && grid[1] == g[1] && grid[2] == g[2]) {
                        fflag = true;
                        return;
                    }
                } else {
                    if (grid[0] == g[0] && grid[1] == g[1] && grid[2] == g[2]) {
                        fflag = true;
                        return;
                    } else {
                        dfs(grid, !flag);
                    }
                }
            }
            grid[i][j] = '.';

            if (fflag)
                return;
        }
    }

}


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    while(n--) {

        fflag= false;
        for (int i = 0; i < 3; i++) {
            cin >> g[i];
        }
        string bg[]={"...","...","..."};
        if(bg[0] == g[0] &&bg[1] == g[1] && bg[2] == g[2])
        {
            cout<<"yes"<<endl;
        }
        else {
            dfs(bg, true);

            if (fflag) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }

    }



    return 0;
}