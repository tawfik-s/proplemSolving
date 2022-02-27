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
string s;
vector<vector<int>>mem;
vector<vector<string>>stmemo;
int solve(int i, int j){
    if(i>j) return 0;
    if(mem[i][j]!=-1)
        return mem[i][j];
    if(s[i]==s[j]) return mem[i][j]=solve(i+1,j-1);
    else{
        int op1=solve(i+1,j)+1;
        int op2=solve(i,j-1)+1;
        return mem[i][j]=min(op1,op2);
    }
}
string Print(int i, int j){
    if(i>j) return "";
    if(i==j) return string(1,s[i]);  //return the middle element
    if(stmemo[i][j]!="$")
        return stmemo[i][j];
    if(s[i]==s[j]) {
        string temp=s[i]+Print(i+1,j-1)+s[j];
        return stmemo[i][j]=temp;
    }
    else{
        int opt=solve(i,j);
        int op1=solve(i+1,j)+1;
        int op2=solve(i,j-1)+1;
        if(opt==op1&&op1!=op2){
            return stmemo[i][j]=Print(i+1,j);
        }
        if(opt==op2&&op1!=op2){
           return stmemo[i][j]=Print(i,j-1);
        }
        return stmemo[i][j]=min(Print(i+1,j),Print(i,j-1));
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while(cin>>s){
        n=s.length();
        mem=vector<vector<int>>(n+3, vector<int>(n+3,-1));
        stmemo=vector<vector<string>>(n+3, vector<string>(n+3,"$"));
        solve(0,n-1);
        cout<<Print(0,n-1)<<'\n';
    }
    return 0;
}