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

    int c;
    cin>>c;
    while(c--)
    {
        int l,m;
        cin>>l>>m;
        l=l*100;
        deque<int>left;deque <int> right;
        int count=0;
        int n; string st;
        for(int i=0;i<m;i++)
        {
            cin>>n>>st;
            if(st=="left")
                left.push_back(n);
            else
                right.push_back(n);
        }
        while(!(left.empty() && right.empty()))
        {
            int ll=0;
            count++;
            while(!left.empty()) {
                ll += left.front();
                if (ll > l)
                    break;
                left.pop_front();
            }
            if((left.empty() && right.empty()))
                break;

            int rr=0;
            count++;
            while(!right.empty()) {
                rr += right.front();
                if (rr > l)
                    break;
                right.pop_front();
            }

        }
        cout<<count<<endl;
    }


    return 0;
}