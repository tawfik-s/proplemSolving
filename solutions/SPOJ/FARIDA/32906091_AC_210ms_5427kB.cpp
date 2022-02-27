
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

vector<vector<ll>>dp;
vector<ll>number;

ll solve(int index,bool last)
{
    if(index==n)
        return 0;
    int ilast=0;
    if(last)
        ilast=1;
    else
        ilast=0;

    if(dp[index][ilast]!=-1e9)
    {
        return dp[index][ilast];
    }

    ll take =0,leave=0;
    if(!last)
    {
        //take
     take=solve(index+1,true)+number[index];
    }
      //leave
      leave=solve(index+1,false);

    return dp[index][ilast]=max(take,leave);

}

// i can't solve iterative so i will solve recursive.

int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
int t;
cin>>t;
int to=0;
while(t--) {
    to++;
    cin >> n;
    dp.clear();
    number.clear();
    dp .resize(n + 2, vector<ll>(2, -1e9));
    number .resize(n + 2, 0);
    for (int i = 0; i < n; i++) {
        cin >> number[i];
    }
    cout << "Case "<<to<<": "<<solve(0, 0)<<endl;

}
    return 0;
}

