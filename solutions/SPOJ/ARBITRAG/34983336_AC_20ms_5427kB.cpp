#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Inf=1e9;



int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif


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
        vector<vector<double>>adj(N, vector<double>(N, 0));
        for(int i=0;i<N;i++)
        {
            adj[i][i]=1;
        }
        for(int i=0;i<M;i++)
        {
            double c;
            string a,b;
            cin>>a>>c>>b;
            adj[mp[a]][mp[b]]=max(c,adj[mp[a]][mp[b]]);
        }
        bool flag=false;
        for (int k = 0; k < N; k++)
            for (int u = 0; u < N; u++)
                for (int v = 0; v < N; v++)
                    adj[u][v] = max(adj[u][v], adj[u][k] * adj[k][v]);


        for (int i = 0; i < N; i++) {
            if (adj[i][i] > 1) {
                flag = true;
                break;
            }
        }


        if(flag)
            cout<< "Case " << num++ << ": "<<"Yes\n";
        else
            cout<< "Case " << num++ << ": "<<"No\n";





    }



    return 0;
}

