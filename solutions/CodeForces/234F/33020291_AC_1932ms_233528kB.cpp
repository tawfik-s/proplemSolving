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
int n,a,b;
vector<int>v;
vector<vector<vector<int>>>memo;
int solve(int index,int g,int r,char last)
{
    if(index==n)
        return 0 ;

    if(g<0||r<0)
        return 1e9;
    int q=0;
    if(last=='g')
        q=1;

    if(memo[index][g][q]!=-1)
        return memo[index][g][q];

    int x=1e9;
    if(g>=v[index])
    {
        if(last=='g')
           x=min(x,solve(index+1,g-v[index],r,'g'));
        else
            x=min(x,solve(index+1,g-v[index],r,'g'))+min(v[index],v[index-1]);
    }
    if(r>=v[index])
    {
        if(last=='r')
             x=min(x,solve(index+1,g,r-v[index],'r'));
        else
            x=min(x,solve(index+1,g,r-v[index],'r')+min(v[index],v[index-1]));
    }

    return memo[index][g][q]=x;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>n>>a>>b;
    v.resize(n);
    memo.resize(n+8,vector<vector<int>>(a+8,vector<int>(2,-1)));
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        sum+=v[i];
        if(v[i]>a&&v[i]>b)
            sum=1e9;
    }
    int ans=min(solve(1,a-v[0],b,'g'),solve(1,a,b-v[0],'r'));

    if(ans>=1e9||sum>a+b)
        cout<<-1;
    else
        cout<<ans;





    return 0;
}