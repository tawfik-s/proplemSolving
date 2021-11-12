#include <bits/stdc++.h>
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;
typedef long long ll;

const int N = 1e5 + 5, M = 1e3 + 5, MOD = 1e9 + 7, OO = 0x3f3f3f3f;
const ll LOO = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-8;

int main()
{
    FIO
        //    freopen("input.txt","rt",stdin);
        //    freopen("output.txt","wt",stdout);

        int n;
    cin >> n;
    vector<int> arr(n);
    int sqr = (int)(ceil(sqrt(n)));
    vector<int> blocks(sqr, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        blocks[i / sqr] += arr[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int l, r, sum = 0;
            cin >> l >> r;
            --l, --r;
            for (int i = l; i <= r;)
            {
                if (i % sqr == 0 && i + sqr - 1 <= r)
                {
                    sum += blocks[i / sqr];
                    i += sqr;
                }
                else
                    sum += arr[i++];
            }
            cout << sum << '\n';
        }
        else
        {
            int indx, newVal;
            cin >> indx >> newVal;
            indx--;
            blocks[indx / sqr] -= arr[indx];
            arr[indx] = newVal;
            blocks[indx / sqr] += arr[indx];
        }
    }

    return 0;
}