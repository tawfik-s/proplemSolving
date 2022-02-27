#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,m,m1;
vector<int>par;
vector<int>sz,sz1;
vector<int>par1;

int findParent(int u)
{
    if(u==par[u]) return u;
    return par[u]= findParent(par[u]);
}
int findParent1(int u)
{
    if(u==par1[u]) return u;
    return par1[u]= findParent1(par1[u]);
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
void join1(int a,int b)
{
    a= findParent1(a);
    b= findParent1(b);
    if(a!=b)
    {
        if(sz1[a]>sz1[b])
        {
            swap(a,b);
        }
        sz1[b]+=sz1[a];
        par1[a]=b;
    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    cin>>n>>m>>m1;
    par.resize(n+1,0);
    sz.resize(n+1,1);
    iota(par.begin(),par.end(),0);
    par1.resize(n+1,0);
    sz1.resize(n+1,1);
    iota(par1.begin(),par1.end(),0);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        join(u,v);
    }
    for(int i=0;i<m1;i++)
    {
        int u,v;
        cin>>u>>v;
        join1(u,v);
    }
   set<pair<int,int>>ss;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
                continue;
            if(findParent(i)!= findParent(j))
            {
                if(findParent1(i)!= findParent1(j))
                {
                    join(i,j);
                    join1(i,j);
                    ss.insert({min(i,j),max(i,j)});
                }

            }
        }
    }
    cout<<ss.size()<<endl;
    for(auto k:ss)
    {
        cout<<k.first<<" "<<k.second<<endl;
    }




    return 0;
}
