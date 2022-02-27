
/*
author: tawfik shalash
─▄█▄─█▀█▀█─▄█▄
▀▀████▄█▄████▀▀
─────▀█▀█▀

*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> ii;
const ll INF = 1e14;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl "\n"
ll M = 1e9 + 7;
ll OO = 1e9;
ll MOD = 1e9 + 7;
int Max = 1e9;

int cur;



int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s1,s2;
    cin>>s1>>s2;

    deque<char>qstr1,qstr2;
    for(auto x:s1)qstr1.push_back(x);
    for(auto x:s2)qstr2.push_back(x);
    while(!qstr1.empty() && !qstr2.empty()) {
        if(qstr1.front() == qstr2.front()) {
            qstr1.pop_front();
            qstr2.pop_front();
        }
        else
        {
            break;
        }
    }
    while(!qstr1.empty() && !qstr2.empty() ) {
       if(qstr1.back() == qstr2.back()) {
            qstr1.pop_back();
            qstr2.pop_back();
        }
       else
       {
           break;
       }
    }

    cout << qstr2.size() << endl;
}
