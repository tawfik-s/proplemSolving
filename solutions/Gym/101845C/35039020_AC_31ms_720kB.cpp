#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef set<int> si;
typedef pair<ll,ll> ii;
const int INF=1e9; int N=2e5+10;
#define fast     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"

int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    string a,b;
    cin>>a>>b;
    int n;
    cin>>n;
    int adjMat[300][300];
    for(int i=0;i<300;i++)
        for(int j=0;j<300;j++) {
            if(i==j)adjMat[i][j]=0;
            else adjMat[i][j] = INF;
        }

    for(int i=0;i<n;i++)
    {
        char a,b;
        int c;
        cin>>a>>b>>c;
        adjMat[a][b]=min(adjMat[a][b],c);
    }

    for(int k=0;k<300;k++)
        for (int i = 0; i < 300; ++i)
            for (int j = 0; j < 300; ++j) {
                if(adjMat[i][k]==INF||adjMat[k][j]==INF)continue;
                adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
            }
    ll cost=0;
    for(int i=0;i<a.length();i++)
    {
        cost+=adjMat[a[i]][b[i]];
    }
    if(cost>INF)
    {
        cout<<-1;
    }
    else
    {
        cout<<cost;
    }





    return 0;
}
