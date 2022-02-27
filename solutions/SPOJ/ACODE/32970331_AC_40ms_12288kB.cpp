
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
string s;
ll memo[(int)1e6];
ll solve(int i)
{
    if(i>s.length())
        return 0;
    if(i==s.length())
        return 1;
    if(s[i]=='0')
        return 0;
    if(~memo[i])
        return memo[i];
    ll sum = 0;
    if(i+1<s.length()) {
        string big = "";
        big += s[i];
        big += s[i + 1];
        int ib = stoi(big);

        if (ib <= 26) {
            sum += solve(i + 2);
        }
    }

        sum+= solve(i+1);

    return memo[i]=sum;
}



int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif


    while(cin>>s)
    {
        if(s=="0")
            return 0;
        memset(memo,-1,sizeof memo);
        cout<<solve(0)<<endl;
    }



    return 0;
}