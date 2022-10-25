#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
//-----------------------------//

int32_t main()
{
    fast();
    int l = 1, r = 1000000, ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        cout << mid << endl;
        cout << flush;
        string s;
        cin >> s;
        if (s.size() == 1)
        { // x < mid
            r = mid - 1;
        }
        else
        { // x>=mid
            ans = mid;
            l = mid + 1;
        }
    }
    cout << '!' << " " << ans;
    cout << flush;
}