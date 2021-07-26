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

    while (cin >> n && n != 0)
    {
        deque<int>deq;
        vector<int>end;
        for(int i=1;i<=n;i++)
        {
            deq.push_back(i);
        }
        while(deq.size()!=1)
        {
            end.push_back(deq.front());
            deq.pop_front();
            if(deq.size()==1)
            {
                break;
            }
            deq.push_back(deq.front());
            deq.pop_front();
        }

        cout<<"Discarded cards:";
        for(int i=0;i<end.size();i++)
        {
            cout<<" "<<end[i];
            if(i<end.size()-1)
                cout<<",";
        }
        cout<<endl;
        cout<<"Remaining card: "<<deq.front()<<endl;
//        1, 3, 5, 7, 4, 2
//        6


    }




    return 0;
}
