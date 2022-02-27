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
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    cin>>n;
    deque<int>d;
    bool reverse=true;
    while (n--)
    {
        string s;
        cin>>s;
        if(s=="back")
        {
            if(reverse) {
                if (d.empty()) {
                    cout << "No job for Ada?" << endl;
                } else {
                    cout << d.back() << endl;
                    d.pop_back();
                }
            }
            else
            {
                if(d.empty())
                {
                    cout<<"No job for Ada?"<<endl;
                }
                else { cout << d.front() << endl;  d.pop_front();}
            }
        }
        else if(s=="front")
        {
            if(reverse) {
                if (d.empty()) {
                    cout << "No job for Ada?" << endl;
                } else {
                    cout << d.front() << endl;
                    d.pop_front();
                }
            }
            else
            {
                if (d.empty()) {
                    cout << "No job for Ada?" << endl;
                } else {
                    cout << d.back() << endl;
                    d.pop_back();
                }
            }
        }
        else if(s=="reverse")
        {
            reverse=!reverse;
        }
        else if(s=="push_back")
        {
            if(reverse) {
                int nj;
                cin >> nj;
                d.push_back(nj);
            }
            else
            {
                int nj;
                cin>>nj;
                d.push_front(nj);
            }
        }
        else if(s=="toFront")
        {
            if(reverse) {
                int nj;
                cin >> nj;
                d.push_front(nj);
            }
            else
            {
                int nj;
                cin >> nj;
                d.push_back(nj);
            }
        }
    }




    return 0;
}
