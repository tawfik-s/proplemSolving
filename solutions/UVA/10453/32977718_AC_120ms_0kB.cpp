
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

vector<vector<int>> memo;
string s, F, S;
int n;

int solve(int i, int j) {
    if (i > j) return 0;

    if (memo[i][j] != -1)
        return memo[i][j];
    if (s[i] == s[j])
        return memo[i][j] = solve(i + 1, j - 1);


    return memo[i][j] = min(solve(i+1,j)+1,solve(i,j-1)+1);
}

void print(int i, int j) {
    if (i > j) {
        return;
    }
    if (s[i] == s[j]) { // if equal add one of them
        F += s[i];
        if (i != j)
            S = s[i] + S;
        print(i + 1, j - 1); // go to next charachters
    } else {   // if not equal see which one you take
        int opt = solve(i, j);
        int op1 = solve(i + 1, j)+1;
        if (opt == op1) { // he take op1 not op2
            F += s[i];
            S = s[i] + S;
            print(i + 1, j);  // go to next element
        } else { // he take op2
            F += s[j];
            S = s[j] + S;
            print(i, j - 1); // move the right pointer
        }
    }

}


int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif


    while (cin >> s) {
        F = S = "";
        n = s.length();
        memo.clear();
        memo = vector<vector<int>>(n, vector<int>(n, -1)); // resze your memoization array
        cout << solve(0, n - 1) << ' ';
        print(0, n - 1);
        cout << F << S << '\n';
    }

    return 0;
}