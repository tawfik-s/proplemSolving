#include <bits/stdc++.h>
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;
typedef long long ll;

const int N = 1e5 + 5, M = 1e3 + 5, MOD = 1e9 + 7, OO = 0x3f3f3f3f;
const ll LOO = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-8;

string a, b, c;
int an, bn, cn;
vector<int> prefix;
vector<vector<vector<int>>> mem;

int getBorder(int br, char ch)
{
    while (br > 0 && ch != c[br])
        br = prefix[br - 1];
    if (ch == c[br])
        br++;
    return br;
}

int solve(int i, int j, int br)
{
    if (br == cn)
        return -OO;
    if (i == an || j == bn)
        return 0;
    if (mem[i][j][br] != -1)
        return mem[i][j][br];
    int ret = 0;
    if (a[i] == b[j])
        ret = max(ret, solve(i + 1, j + 1, getBorder(br, a[i])) + 1);
    ret = max(ret, solve(i + 1, j, br));
    ret = max(ret, solve(i, j + 1, br));
    return mem[i][j][br] = ret;
}

void print(int i, int j, int br)
{
    if (br == cn)
        return;
    if (i == an || j == bn)
        return;
    int opt = solve(i, j, br);
    if (a[i] == b[j] && opt == solve(i + 1, j + 1, getBorder(br, a[i])) + 1)
    {
        cout << a[i];
        print(i + 1, j + 1, getBorder(br, a[i]));
        return;
    }
    if (opt == solve(i + 1, j, br))
        print(i + 1, j, br);
    else
        print(i, j + 1, br);
}

int main()
{
    FIO
            //    freopen("input.txt","rt",stdin);
            //    freopen("output.txt","wt",stdout);

            cin >>
        a >> b >> c;
    an = a.length();
    bn = b.length();
    cn = c.length();
    mem = vector<vector<vector<int>>>(an, vector<vector<int>>(bn, vector<int>(cn + 1, -1)));
    prefix = vector<int>(cn);
    prefix[0] = 0;
    for (int i = 1; i < cn; i++)
        prefix[i] = getBorder(prefix[i - 1], c[i]);
    if (solve(0, 0, 0))
        print(0, 0, 0);
    else
        cout << 0;
    cout << '\n';

    return 0;
}
