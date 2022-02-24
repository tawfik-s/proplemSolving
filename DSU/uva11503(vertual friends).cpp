#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 1e9;


class DSU {
private:
    vector<int> par, sz;   //parent and size vector
    ll ret = 0;
public:
    DSU(int x) {
        x++;
        par.resize(x);
        sz.resize(x, 1);
        iota(par.begin(), par.end(), 0);

    }

    int findParent(int u)  //recursive function to find parent
    {
        if (u == par[u])
            return u;
        return par[u] = findParent(par[u]);
    }

    //to join two sets
    void join(int a, int b) {
        a = findParent(a);
        b = findParent(b);

        if (a != b) {
            if (sz[a] > sz[b])
                swap(a, b);
            par[a] = b;
            sz[b] += sz[a];

        }
    }
    bool inTheSameGroup(int a,int b)
    {
        a=findParent(a);
        b=findParent(b);
        return a==b;
    }
    int sizeOfGroup(int node)
    {
        int a= findParent(node);
        return sz[a];
    }


};

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
            int n;
            cin>>n;
            DSU dsu=DSU((int)1e5*3);
            map<string,int>mp;
            int count=1;
            for(int i=0;i<n;i++)
            {
                string a,b;
                cin>>a>>b;
                if(mp[a]==0)
                {
                    mp[a]=count++;
                }
                if(mp[b]==0)
                {
                    mp[b]=count++;
                }
                dsu.join(mp[a],mp[b]);
                cout<<dsu.sizeOfGroup(mp[a])<<endl;
            }
        }


    return 0;
}
