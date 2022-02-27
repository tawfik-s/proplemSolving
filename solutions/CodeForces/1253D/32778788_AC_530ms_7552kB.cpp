#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,m;
vector<int>par;

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
        par[a]=max(a,b);
        par[b]=max(a,b);
    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    cin>>n>>m;
    par.resize(n+1,0);
    iota(par.begin(),par.end(),0);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        join(u,v);
    }
    int num=0;
    for(int i=1;i<=n;)
    {
        int parent= findParent(i);

        for(int j=i+1;j<parent;j++)
        {
            if(findParent(j)!= findParent(i))
            {
                num++;
                join(i,j);
            }
        }

        i= max(i+1, parent);
    }

    cout<<num;





    return 0;
}
