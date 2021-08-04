// Author : tawfik shalash
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
#include <bits/stdc++.h>
//cpp 11
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl "\n"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;

int main()
{

    // fast
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

 int n;
 while(true)
 {
     cin>>n;
     if(n==0)
        return 0;

      vector<int>v(n);
      for(int i=0;i<n;i++)
      {
          cin>>v[i];
      }   
  
        int res = 0;
        while (v.size() > 1) {

            sort(v.begin(), v.end());

            int newel = v[0] + v[1];

            res += newel;

            v[1] = newel;

           v.erase(v.begin());
        }
        cout << res << endl;


 }









    return 0;
}