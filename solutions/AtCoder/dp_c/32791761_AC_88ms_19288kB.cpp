#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
vector<array<int,3>>v;
ll mAx=1e12;
vector<vector<ll>>vis;
ll solve(int last,int index,ll sum)
{
    if(index==n)
        return 0;

    if(vis[index][last]!=0)
        return vis[index][last];

    ll cha=0,chb=0,chc=0;


    if(last!=1)
     cha=solve(1,index+1,sum)+v[index][0];
    if(last!=2)
    chb=solve(2,index+1,sum)+v[index][1];
    if(last!=3)
    chc=solve(3,index+1,sum)+v[index][2];


    return vis[index][last]=max(cha,max(chb,chc));
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif


    cin>>n;
    v.resize(n);
    vis.resize(n+1,vector<ll>(4,0));

    for(int i=0;i<n;i++)
    {
        cin>>v[i][0]>>v[i][1]>>v[i][2];
    }
    cout<<solve(0,0,0);





    return 0;
}