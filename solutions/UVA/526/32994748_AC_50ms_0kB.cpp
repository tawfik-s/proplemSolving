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
ll M = 1e9 + 7;
string s1, s2;
int tc=0;
vector<vector<int>>mem;
int solve(int i, int j) {
    if (i == s1.length()) {
        return s2.length() - j;
    }
    if (j == s2.length()) {
        return s1.length() - i;
    }
    if(mem[i][j]!=-1)
    {
        return mem[i][j];
    }
    if(s1[i]==s2[j]) return mem[i][j]=solve(i+1,j+1);

    int op1=solve(i+1,j+1)+1;
    int op2=solve(i+1,j)+1;
    int op3=solve(i,j+1)+1;

    return mem[i][j]=min({op1,op2,op3});
}
int f=0;

void print(int i,int j)
{
    if (i == s1.length()) {
       for(int k=0;k<s2.length()-j;k++)
       {
            cout<<++tc<<" Insert "<<i+k+1+f<<','<<s2[j+k]<<endl;
//            f+=s2.length()-j;
         // f++;
       }
       return;
    }
    if (j == s2.length()) {
        for(int k=0;k<s1.length()-i;k++)
        {
            cout<<++tc<<" Delete "<<i+k+1+f<<endl;
            f--;
        }
        return;
    }
    if(s1[i]==s2[j])
    {
        print(i+1,j+1);
         solve(i,j);return;
    }
    int op=solve(i,j);
    int op1=solve(i+1,j+1)+1;
    int op2=solve(i+1,j)+1;
    int op3=solve(i,j+1)+1;
    if(op==op1)
    {
        cout<<++tc<<" Replace " <<i+1+f<<','<<s2[j]<<endl;
         print(i+1,j+1);return;
    }
    else
    if(op==op2)
    {
        cout<<++tc<<" Delete "<<i+1+f<<endl;
        f--;
         print(i+1,j);return;
    }
    else
    if(op==op3)
    {
        cout<<++tc<<" Insert "<<i+1+f<<','<<s2[j]<<endl;
        f++;
         print(i,j+1);
         return;
    }

}


int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    bool flag=false;
    while(getline(cin,s1))
    {
        if(flag)
        {
            cout<<endl;
        }
        flag=true;

        getline(cin,s2);
        tc=0;
        f=0;
        mem=vector<vector<int>>(100,vector<int>(100,-1));
        cout<<solve(0,0)<<endl;
        print(0,0);
    }

    return 0;
}