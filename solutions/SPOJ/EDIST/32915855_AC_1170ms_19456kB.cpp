
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
int M=1e9+7;
string s1,s2;
vector<vector<int>>dp;
int solve(int i,int j)
{
    if(i>=s1.length()||j>=s2.length())
    {
        return abs((int)(abs((int)s1.length()-i)-abs((int)s2.length()-j)));
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int res=1e9;
    if(s1[i]==s2[j])
    {
       res=min(solve(i+1,j+1),res);
    }
    else
    {
        res=min(solve(i+1,j)+1,res);
        res=min(solve(i,j+1)+1,res);
        res=min(solve(i+1,j+1)+1,res);
    }

    return dp[i][j]=res;
}

// i can't solve iterative so i will solve recursive.

int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin>>t;
    while(t--)
    {

        cin>>s1>>s2;
        dp.clear();
        dp.resize((int)s1.length(),vector<int>((int)s2.length(),-1));
        cout<<solve(0,0)<<endl;

    }



    return 0;
}

