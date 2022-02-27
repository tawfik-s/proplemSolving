// Author : tawfik shalash
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
#include<bits/stdc++.h>
//cpp 11
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
#define fast     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;


int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif


    string s;
    int nn=0;
    while(true) {
        cin >> s;
        if (s.find('-') != string::npos)
            return 0;
        nn++;
        stack<char> st;
        int x = 0;
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (ch == '{')
            {
                st.push(ch);
            }
            else if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else {
                x++;
                st.push('{');
            }
        }
        x += st.size() / 2;
         cout<<nn<<". "<<x<<endl;
    }

    return 0;
}
