// Author : tawfik shalash
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef set<int> si;
typedef pair<ll,int> ii;
const ll INF=1e14;
#define fast     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"

int n,m,X,Y,xs,ys;
vector<vector<ll>>mem;
vector<pair<int,int>>points;
int solve(int cur,ll mask)
{
    if(mask==(1<<n)-1)
        return 0;
    if(mem[cur][mask]!=-1)
        return mem[cur][mask];
    int ret=(int)1e9;
    int x=0;
    for(int nxt=0;nxt<n;nxt++)
    {
        if((mask>>nxt)&1)continue;
        ret=min(ret,abs(abs(points[cur].first-points[nxt].first)
        +abs(points[cur].second-points[nxt].second))+solve(nxt,mask|1<<nxt));
        if((mask|1<<nxt)==(1<<n)-1)
        {
            ret+=abs(abs(xs-points[nxt].first)+abs(ys-points[nxt].second));
        }
    }

    return mem[cur][mask]=ret;
}

int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    int t;
    cin>>t;
    while(t--)
    {
        cin>>X>>Y>>xs>>ys;
        cin>>n;
        n++;
        mem=vector<vector<ll>>(n,vector<ll>(1<<n,-1));
        points.clear();
        points.resize(n);
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            points[i]={a,b};
        }
        points[n-1]={xs,ys};

        int ans=solve(n-1,1<<(n-1));
        if(ans>=(int)1e9)
            cout<<-1;
        else
            cout<<"The shortest path has length "<<ans<<'\n';





    }


    return 0;
}


