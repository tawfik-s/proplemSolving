#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

string g[3];

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


    while(true) {

        fflag= false;
        string sss;
        cin>>sss;
        if(sss=="end")
            return 0;

        g[0]="";
        g[0]+=sss[0];g[0]+=sss[1];g[0]+=sss[2];
        g[1]="";
        g[1]+=sss[3];g[1]+=sss[4];g[1]+=sss[5];
        g[2]="";
        g[2]+=sss[6];g[2]+=sss[7];g[2]+=sss[8];

        string bg[]={"...","...","..."};
        int count=0;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            {
                if(g[i][j]=='.')
                    count++;
            }

            dfs(bg, true);

            if (fflag&& check(g)) {
                cout << "valid" << endl;
            } else if(count==0&&fflag)
            {
                cout<<"valid"<<endl;
            }
            else {
                cout << "invalid" << endl;
            }

    }



    return 0;
}