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


    int N,M,num=1;
    while(cin>>N&&N)
    {
        map<string,int>mp;
        for(int i=0;i<N;i++)
        {
            string s;
            cin>>s;
            mp[s]=i;
        }

        cin >> M;
        vector<vector<pair<int,double>>>adj(3e5);
        vector<double> dist(3e5,-Inf);

        while(M--)
        {
            double c;
            string a,b;
            cin>>a>>c>>b;
            adj[mp[a]].push_back({mp[b], c});
        }
        bool flag=false;
        dist[0] = 1.0;
        for(int t=0;t<N;t++)
        {
            for(int i=0;i<N;i++)
            {
                for(int j=0; j < adj[i].size(); j++)
                {
                    if(dist[adj[i][j].first]<dist[i]*adj[i][j].second) {
                        if(t==N-1)
                            flag = true;
                        dist[adj[i][j].first] = dist[i] * adj[i][j].second;
                    }
                }
            }
        }


        if(flag)
            cout<< "Case " << num++ << ": "<<"Yes\n";
        else
            cout<< "Case " << num++ << ": "<<"No\n";





    }



    return 0;
}