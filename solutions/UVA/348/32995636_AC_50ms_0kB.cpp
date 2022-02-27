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
vector<vector<int>>mem;
int n;
vector<int>row,col,bef,af;

int solve(int s,int e)
{
    if(s==e)
        return 0;
    if(mem[s][e]!=-1)
        return mem[s][e];
    int ret=1e9;
    for(int i=s;i<e;i++)
    {
        ret=min(ret,solve(s,i)+solve(i+1,e)+row[s]*col[i]*col[e]); //find the minimum solution
    }
    return mem[s][e]=ret;
}
void print(int s,int e)
{
    if(s==e)
        return;
    int opt=solve(s,e);
    int ret=1e9;
    int mid=-1;
    for(int i=s;i<e;i++)
    {
        ret=min(ret,solve(s,i)+solve(i+1,e)+row[s]*col[i]*col[e]);
        if(ret==opt)
        {
            mid=i;
            break;
        }
    }
    if(s!=mid)
    {
        bef[s]++;
        af[mid]++;
    }
    if(mid+1!=e)
    {
        bef[mid+1]++;
        af[e]++;
    }
    print(s,mid);
    print(mid+1,e);
}


int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int cnt=0;
    while(cin>>n,n)
    {
        mem.clear();
        row.resize(n);
        col.resize(n);
        bef=vector<int>(n,0);
        af=vector<int>(n,0);
        mem.resize(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            cin>>row[i]>>col[i];
        }
        solve(0,n-1);
        print(0,n-1);
        cout<<"Case "<<++cnt<<": (";

        for(int i=0;i<n;i++)
        {
            cout<<string(bef[i],'(')<<'A'<<i+1<<string(af[i],')');
            if(i!=n-1)cout<<" x ";
        }
        cout<<")\n";



    }



    return 0;
}