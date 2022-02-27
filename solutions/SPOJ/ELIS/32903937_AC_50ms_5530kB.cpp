
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
int n;

vector<vector<int>>dp;
vector<int>number;

int solve(int index,int last)
{
    if(index==n)
        return 0;
    if(dp[index][last]!=-1e9)
    {
        return dp[index][last];
    }
    int take =0,leave=0;
    if(number[index]>last)
    {
        //take
     take=solve(index+1,number[index])+1;
    }
      //leave
      leave=solve(index+1,last);

    return dp[index][last]=max(take,leave);

}

// i can't solve iterative so i will solve recursive.

int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    cin>>n;
    dp=vector<vector<int>>(n+2,vector<int>(1000,-1e9));
    number=vector<int>(n+2,0);
    for(int i=0;i<n;i++)
    {
        cin>>number[i];
    }
    cout<<solve(0,0);


    return 0;
}

