#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<pair<int,pair<int,int>>>edge;
vector<int>par,sz;
ll ret=0;
int n,m;



int findParent(int u)
{
    if(u==par[u]) return u;

    return par[u]=findParent(par[u]);
}

void join(int a,int b)
{
    a=findParent(a);
    b=findParent(b);

    if(a!=b)
    {
        if(sz[a]>sz[b])
            swap(a,b);
        par[a]=b;
        sz[b]+=sz[a];
    }
}
set<pair<int,int>>resSet;
void kruskal(){
    //sort(edge.begin(),edge.end());
    iota(par.begin(),par.end(),0);

    for(auto e:edge)
    {
        int u=e.second.first;
        int v=e.second.second;
        int c=e.first;

        if(findParent(u)!= findParent(v))
        {
            ret+=c;
            join(u,v);
            resSet.insert({min(u, v), max(u, v)});
        }
    }

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    cin>>n;

    par.resize(26,0);
    sz.resize(26,1);
    ret=0;
    string s1,s2;
    cin>>s1>>s2;
    for(int i=0;i<n;i++)
    {
        int u=(int)(s1[i]-'a');
        int v=(int)(s2[i]-'a');
        int c=1;
        if(u!=v)
        edge.push_back({c,{u,v}});
    }
    kruskal();
    cout<<ret<<endl;
    for(auto kk:resSet)
    {
        char cha=(char)(kk.first+'a');
        char chb=(char)(kk.second+'a');
        cout<<cha<<" "<<chb<<endl;
    }


    return 0;
}


