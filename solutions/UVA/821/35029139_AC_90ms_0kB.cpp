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

    int a,b;
    int nn=1;
    while(cin>>a>>b&&a&&b)
    {
        auto adjmat=vector<vector<int>>(200,vector<int>(200,INF));
        for(int i=0;i<200;i++)
            adjmat[i][i]=0;
        adjmat[a][b]=1;
        while(true)
        {
            cin>>a>>b;
            if(!(a+b))
            {
                break;
            }
            adjmat[a][b]=1;
        }
        for(int k=1;k<=100;k++)
            for(int i=1;i<=100;i++)
                for(int j=1;j<=100;j++)
                {

                    adjmat[i][j]=min(adjmat[i][j],adjmat[i][k]+adjmat[k][j]);
                }

        double sum=0;
        int num=0;
        for(int i=1;i<=100;i++)
            for(int j=1;j<=100;j++)
            {
                if(adjmat[i][j]<INF&&i!=j)
                {
                    sum+=adjmat[i][j];
                    num++;
                }
            }
        cout<<"Case "<<nn++<<": average length between pages = "<<
        fixed<<setprecision(3)<<(double)sum/(double)num
        <<" clicks"<<endl;

    }


    return 0;
}
