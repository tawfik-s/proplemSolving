
/*
author: tawfik shalash
　　██░▀██████████████▀░██
　　█▌▒▒░████████████░▒▒▐█
　　█░▒▒▒░██████████░▒▒▒░█
　　▌░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▐
　　░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░
　 ███▀▀▀██▄▒▒▒▒▒▒▒▄██▀▀▀██
　 ██░░░▐█░▀█▒▒▒▒▒█▀░█▌░░░█
　 ▐▌░░░▐▄▌░▐▌▒▒▒▐▌░▐▄▌░░▐▌
　　█░░░▐█▌░░▌▒▒▒▐░░▐█▌░░█
　　▒▀▄▄▄█▄▄▄▌░▄░▐▄▄▄█▄▄▀▒
　　░░░░░░░░░░└┴┘░░░░░░░░░
　　██▄▄░░░░░░░░░░░░░░▄▄██
　　████████▒▒▒▒▒▒████████
　　█▀░░███▒▒░░▒░░▒▀██████
　　█▒░███▒▒╖░░╥░░╓▒▐█████
　　█▒░▀▀▀░░║░░║░░║░░█████
　　██▄▄▄▄▀▀┴┴╚╧╧╝╧╧╝┴┴███
　　██████████████████████


*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,m,x,y;
vector<int>f;  //for dots
int memo[1000+9][1000+9][2];
int solve(int index,int num,char ch)
{
    if(index == m)
    {
        if(num < x || num > y)
            return 100000000;
        return 0;
    }

    int xy;
    if(ch=='.')
        xy=0;
    else
        xy=1;
    if(memo[index][num][xy]!=-1)
    {
        return memo[index][num][xy];
    }

    int sum=1e9;
    int leave=f[index];
    int take=n-f[index];

    if(ch=='.')
    {
        if(num<y) {
            sum = min(sum, solve(index + 1, num + 1, '.') + take);
            if(num>=x)
                sum=min(sum,solve(index+1,1,'#')+leave);
        }
        else
            sum=min(sum,solve(index+1,1,'#')+leave);
    }

    if(ch=='#')
    {
        if(num<y) {
            sum = min(sum, solve(index + 1, num + 1, '#') + leave);
            if (num >= x)
                sum = min(sum, solve(index + 1, 1, '.') + take);
        }
        else
        {
            sum = min(sum, solve(index + 1, 1, '.') + take);
        }
    }


    return memo[index][num][xy]=sum;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    cin>>n>>m>>x>>y;
    f.resize(m,0);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            char ch;
            cin>>ch;
            if(ch=='.')
                f[j]++;
        }



    memset(memo, -1, sizeof(memo));

         int sum=1e9;
        sum=min(sum,solve(1,1,'#')+f[0]);
        sum=min(sum, solve(1,1,'.')+n-f[0]);

    cout<<sum;





    return 0;
}