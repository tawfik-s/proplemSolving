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

    while(1) {
        int n;
        cin >> n;
        if (n == 0)
            break;

        // loop
        while(true) {
            bool flag2 = false;
            vector<int> v(n);
            for (int i = 0; i < n; i++) {
                cin >> v[i];
                if (v[0] == 0) {
                    flag2 = true;
                    break;
                }
            }
            if(flag2)
                break;
           stack<int> stak;
           int g=1;

          int pt=0;


          while(true)  {
              if(stak.empty())
              {
                  if(pt==n-1||pt==n)
                      break;
                  else
                  {
                      stak.push(g++);
                      continue;
                  }
              }
              int flagg=false;
                while(!stak.empty()&&stak.top() == v[pt]) {
                    stak.pop();
                    pt++;
                    flagg=true;
                }
                if(!flagg)
                {
                    stak.push(g++);
                }
                if (!stak.empty()&&stak.top() > n) {
                    flag2 = true;
                    break;
                }
            }

            if(flag2)
                cout<<"No"<<endl;
            else
                cout<<"Yes"<<endl;

        }
        cout<<endl;

    }
    return 0;
}