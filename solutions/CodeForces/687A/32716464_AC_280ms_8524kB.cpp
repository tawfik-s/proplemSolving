#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,m;
int col[100100];
vector<int> adj[100100];
bool vis[100100];

bool ok=true;

void dfs(int nd,int c){
    col[nd]=c;
    vis[nd]=true;
    for(int i=0;i<adj[nd].size();i++){
        int ch=adj[nd][i];
        if(vis[ch]){
            if(col[ch]==c){
                ok=false;
            }
        } else {
            dfs(ch,3-c);
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        vis[i]=false;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,1);
        }
    }
    if(!ok){
        cout<<-1<<endl;
    } else {
        int cnt1=0;
        for(int i=1;i<=n;i++){
            if(col[i]==1){
                cnt1++;
            }
        }
        cout<<cnt1<<endl;
        for(int i=1;i<=n;i++){
            if(col[i]==1){
                cout<<i<<" ";
            }
        }
        printf("\n");
        int cnt2=0;
        for(int i=1;i<=n;i++){
            if(col[i]==2){
                cnt2++;
            }
        }
        cout<<cnt2<<endl;
        for(int i=1;i<=n;i++){
            if(col[i]==2){
                cout<<i<<" ";
            }
        }
    }
}