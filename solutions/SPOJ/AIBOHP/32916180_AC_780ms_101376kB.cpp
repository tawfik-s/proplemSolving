
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
    while(t--) {
        string a, b;
        cin >> a;
         b=a;
         reverse(b.begin(),b.end());
        int n = a.length();
        int m = b.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        cout << n-dp[n][m] << '\n';

    }

    return 0;
}

