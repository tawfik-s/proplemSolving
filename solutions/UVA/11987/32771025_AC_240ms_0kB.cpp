#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<pair<int,pair<int,int>>>edge;
vector<int>par,sz,sumation,id;
ll ret=0;
int n,m;



int findParent(int u)
{
    if(u==par[u]) return u;
    return par[u]=findParent(par[u]);
}

void join(int a,int b)
{
    a=findParent(id[a]);
    b=findParent(id[b]);

    if(a!=b)
    {
        if(sz[a]>sz[b])
            swap(a,b);
        par[a]=b;
        sz[b]+=sz[a];
        sumation[b]+=sumation[a];
    }
}

void move(int a,int b)
{
    int pa=findParent(id[a]);
    int pb=findParent(id[b]);

    if(pa!=pb)
    {
        sz[pa]--;
        sumation[pa]-=a;

        n++;
        id[a]=n;
        sz.push_back(1);
        sumation.push_back(a);
        par.push_back(n);

        join(a,b);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    while(cin>>n>>m) {
        par.clear();
        sumation.clear();
        sz.clear();
        id.clear();
        par.resize(n + 1, 0);
        sumation.resize(n + 1, 0);
        id.resize(n + 1, 0);
        iota(sumation.begin(), sumation.end(), 0);
        iota(id.begin(), id.end(), 0);
        sz.resize(n + 1, 1);
        iota(par.begin(), par.end(), 0);
        int a;
        while (m--) {
            int b, c;
            cin >> a;
            if (a == 1) {
                cin >> b >> c;
                join(b, c);
            } else if (a == 2) {
                cin >> b >> c;
                move(b, c);
            } else {
                cin >> b;
                int siz = sz[findParent(id[b])];
                int summ = sumation[findParent(id[b])];
                cout << siz << " " << summ << "\n";
            }

        }
    }


    return 0;
}


