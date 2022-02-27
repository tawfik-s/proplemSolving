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

  int n,m;
  int num=1;
  while(cin>>n>>m){

      if(n==0&&m==0)
      {
          return 0;
      }
      cout<<"Network "<<num++<<": ";
      map<string,int>mp;
      int cnt=1;
      vector<vector<int>>cost(n+1,vector<int>(n+1,INF));
      for(int i=0;i<=n;i++)
          cost[i][i]=0;

      for(int i=0;i<m;i++)
      {
          string a,b;
          cin>>a>>b;
          if(mp[a]==0)
          {
              mp[a]=cnt++;
          }
          if(mp[b]==0)
          {
              mp[b]=cnt++;
          }
          cost[mp[a]][mp[b]]=1;
          cost[mp[b]][mp[a]]=1;
      }
      for(int k=1;k<=n;k++)
          for(int i=1;i<=n;i++)
              for(int j=1; j <= n; j++) {
                  if(cost[i][k]>=INF||cost[k][j]>=INF)continue;
                  cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
              }
      int res=0;
      for (int i = 1; i <=n; ++i) {
          for (int j = 1; j <=n ; ++j) {
              res=max(cost[i][j],res);
          }
      }
     if(res>=INF)
     {
         cout<<"DISCONNECTED"<<endl;
     }
     else{
         cout<<res<<endl;
     }
     cout<<endl;

  }




    return 0;
}