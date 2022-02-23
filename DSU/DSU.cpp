#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class DSU {
private:
    vector<int> par, sz;   //parent and size vector
    ll ret = 0;
    int n;
public:
    DSU(int x) {
        n=x;
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
    ~DSU(){

    }
};