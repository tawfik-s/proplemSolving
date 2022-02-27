#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
vector<int>par,en,nxt;

int findParent(int u)
{
    if(u==par[u]) return u;
    return par[u]= findParent(par[u]);
}

int join(int a,int b)
{
     a=findParent(a);
     b=findParent(b);

     if(a!=b)
     {
         par[b]=a;
         nxt[en[a]]=b;
         en[a]=en[b];
     }

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>n;
    par.resize(n+1);
    en.resize(n+1);
    nxt.resize(n+1,-1);
    iota(par.begin(),par.end(),0);
    iota(en.begin(),en.end(),0);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        join(u,v);
    }
    int i= findParent(1);
    while(i!=-1)
    {
        cout<<i<<' ';
        i=nxt[i];
    }






    return 0;
}