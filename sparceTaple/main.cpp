#include <bits/stdc++.h>
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;
typedef long long ll;

const int N = 1e5 + 5, M = 1e3 + 5, MOD = 1e9 + 7, OO = 0x3f3f3f3f;
const ll LOO = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-8;

int n;
vector<int> arr;
vector<vector<int>> table;

int Log(int x)
{
    return 31 - __builtin_clz(x);
}

void buildTable()
{
    table = vector<vector<int>>(n, vector<int>(Log(n) + 1));
    for (int i = 0; i < n; i++)
        table[i][0] = arr[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 0; i + (1 << j) - 1 < n; i++)
            table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r)
{

    int j = Log(r - l + 1);
    return min(table[l][j], table[r - (1 << j) + 1][j]);

    // int len=r-l+1;
    // int ls=Log(len);
    // int st=l;
    // int mn=OO;
    // for(int j=0; j<=ls; j++){
    //     if((len>>j)&1){
    //         mn=min(mn,table[st][j]);
    //         st+=(1<<j);
    //     }
    // }
    // return mn;
}

int main()
{
    FIO
            //    freopen("input.txt","rt",stdin);
            //    freopen("output.txt","wt",stdout);

            cin >>
        n;
    arr = vector<int>(n);
    for (int &x : arr)
        cin >> x;
    buildTable();
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << '\n';
    }

    return 0;
}