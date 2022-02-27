#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,m;
vector<int>par,sz;

int findParent(int u)
{
    if(u==par[u]) return u;
    return par[u]= findParent(par[u]);
}

void join(int a,int b)
{
    a= findParent(a);
    b= findParent(b);
    if(a!=b)
    {
        if(sz[a]>sz[b])
        {
            swap(a,b);
        }
        sz[b]+=sz[a];
        par[a]=b;
    }
}

ll exponentiation(ll a,ll b,ll modd=1e9+7)
{
    if(b==0) return 1;
    if(b==1) return a;

    ll t= exponentiation(a,b/2);
    t=t%modd;
    if(b%2==1)
    {
        return (((t*t)%modd)*a)%modd;
    }
    else
    {
        return ((t*t)%modd);
    }

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    cin>>n>>m;
    par.resize(n,0);
    sz.resize(n,1);
    iota(par.begin(),par.end(),0);
    for(int i=1;i<n;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        if(c==0)
        {
            u--;v--;
            join(u,v);
        }
    }
    set<int>elem;
    for(int i=0;i<n;i++)
    {
        elem.insert(findParent(i));
    }
    ll ans= exponentiation(n,m);
    ll mm=1e9+7;
    for(auto k:elem)
    {
        ans=((ans- exponentiation(sz[k],m)+mm)%mm);
    }
    cout<<ans;







    return 0;
}
