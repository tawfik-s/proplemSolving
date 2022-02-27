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
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int,int> ii;
const int INF=(int)1e9;
#define fast     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"
int n,m;

vector<pair<int,ii>>adjList;
pair<bool,ll>bellman(int src,int tar)
{
    vi dis(n,INF);
    dis[src]=0;
    bool hasCycle=0;
    for(int i=0;i<n;i++)
    {
        bool isUpdated=0;
        for(auto e:adjList)
        {
            if(dis[e.second.second]>dis[e.second.first]+e.first)
            {
                dis[e.second.second]=dis[e.second.first]+e.first;
                isUpdated=1;
            }
        }
        if(isUpdated==0)
            break;
        else if(i==n-1)
            hasCycle=1;
    }

    return {hasCycle,dis[tar]};

}
int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int t;
    cin>>t;
    for(int T=0;T<t;T++)
    {
        adjList.clear();int sr,sc;
        cin>>n>>m;
        adjList.resize(m);
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            adjList[i]={c,{a,b}};
        }

        if(bellman(0,n-1).first)
            cout<<"possible"<<endl;
        else
            cout<<"not possible"<<endl;

    }




    return 0;
}








