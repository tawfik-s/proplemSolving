#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Inf=1e9;



int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    int T;
    cin>>T;
    while(T--)
    {
        int N,M;
        cin >> N >> M;
        vector<pair<int,int>>adj[2000];
        vector<int> dist(2000,Inf);

        while(M--)
        {
            int a,b,c;
            cin>>a>>b>>c;
            adj[a].push_back({b, c});
        }
        bool flag=false;
        for(int t=0;t<N-1;t++)
        {
            for(int i=0;i<N;i++)
            {
                for(int j=0; j < adj[i].size(); j++)
                {
                    dist[adj[i][j].first]=min(dist[adj[i][j].first], dist[i] + adj[i][j].second);
                }
            }
        }

        
        for(int i=0;i<N;i++)
        {
            for(int j=0; j < adj[i].size(); j++)
            {
                if(dist[adj[i][j].first]>dist[i]+adj[i][j].second)
                flag=true;
            }
        }
        if(flag)
            cout<<"possible\n";
        else
            cout<<"not possible\n";





    }



    return 0;
}

