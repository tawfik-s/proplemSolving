#include<bits/stdc++.h>


//
//**********************************************************
//**********************************************************
//**********************************************************
//**********************************************************
//**********************tawfik shalash**********************
//**********************************************************
//**********************************************************
//**********************************************************
//**********************************************************

using namespace std;
typedef long long ll;

const int oo=1e9;ll mAx=1e12; ll mod9=1e9;

vector<ll>v;
ll vis [100009];

int n,k;
ll solve(int index)
{
    if(index==n-1)
        return 0;

    if(vis[index]!=-1)
        return vis[index];

    vis[index]=oo;

    ll step=oo,tstep=oo;

    for(int i=1;i<=k;i++) {
        if (index + i < n) {
            step = solve(index + i) + abs(v[index] - v[index + i]);
            vis[index] = min(vis[index], step);
        }
    }


    return vis[index];
}




int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif


    cin>>n>>k;
    v.resize(n);
    memset(vis,-1,sizeof vis);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    cout<<solve(0);






    return 0;
}
