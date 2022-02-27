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
#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
ll M=1e9+7;
int t, k, L = (int) 1e5,mx=0;
vector<int>v,price; int c,n;
vector<int>memo;

int solve(int i)
{
    if(i==n)
        return 0;
    if(memo[i]!=-1)
        return memo[i];
    int sum=10,x=(int)1e9;
    for(int j=i;j<n;j++)
    {
        sum+=v[j];
        x=min(x,solve(j+1)+(sum*price[j]));
    }
    return memo[i]=x;
}
int main() {


    cin>>t;
    while(t--)
    {
        cin>>n;
        v=vector<int>(n);
        price=vector<int>(n);
        memo=vector<int>(n,-1);
        for(int i=0;i<n;i++)
        {
            cin>>v[i]>>price[i];
        }
      cout<<solve(0)<<endl;
    }





    return 0;
}