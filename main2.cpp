#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef set<ll> sll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
const ll INF = (ll) 1e12;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl "\n"


int main() {

	fast

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<pair<int, int>> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i].first >> v[i].second;
		}
		map<int, bool> mp1, mp2;
		vector<pair<int,int>>ss1,ss2;
		bool flag = true;
		for (int i = 0; i < n; i++) {
			if (v[i].first == v[i].second) {
				cout << "NO\n";
				flag = false;
				break;
			}
			if (mp1.find(v[i].first) == mp1.end() &&
					mp1.find(v[i].second) == mp1.end()) {
				mp1[v[i].first] = true;
				mp1[v[i].second] = true;
				ss1.push_back(v[i]);
			} else if (mp2.find(v[i].first) == mp2.end() &&
					mp2.find(v[i].second) == mp2.end()) {
				mp2[v[i].first] = true;
				mp2[v[i].second] = true;
				ss2.push_back(v[i]);
			} else {
				cout << "NO\n";
				flag = false;
				break;
			}

		}


		if (flag) {
			cout << "YES"<<endl;
		}


	}

	return 0;
}

