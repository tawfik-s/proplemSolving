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
    ~DSU(){

    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    int n;
    cin >> n;
    string x;
    cin >> x;
    while (n--) {
        DSU dsu =DSU(stoi(x));
        int s = 0, f = 0;
         bool flag=true;
        while ( cin >> x ) {
            int a, b;
            if (x == "c") {
                flag=true;
                cin>>a>>b;
                dsu.join(a, b);
            } else if (x == "q") {
                flag=true;
                cin>>a>>b;
                if (dsu.findParent(a) == dsu.findParent(b)) {
                    s++;
                } else {
                    f++;
                }
            } else {
                flag=false;
                cout << s << "," << f << endl;
                break;
            }
        }
        if(flag)
        {
            cout << s << "," << f << endl;
        }

        if(n!=0)
        {
            cout<<endl;
        }
    }


    return 0;
}