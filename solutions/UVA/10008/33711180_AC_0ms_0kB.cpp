
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
int Max = 1e9, q;
int n;


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

   int n;
   cin>>n;
   string s;
   vector<ll>v(26,0);
    while(cin>>s)
   {
       for(int i=0;i<s.size();i++)
       {
           int as=(int)s[i];
           if(as>=97&&122>=as)
           {
               as-=97;
               v[as]++;
           }
           else if(as>=65&&as<=90)
           {
               as-=65;
               v[as]++;
           }
       }
   }
    vector<pair<ll,int>>vv;
    for(int i=0;i<26;i++)
    {
        if(v[i]!=0)
        vv.emplace_back(v[i],-1*(int)(i+'A'));
    }
    sort(vv.begin(),vv.end());
    reverse(vv.begin(),vv.end());
    for(auto x:vv)
    {
        cout<<(char)(-1*x.second)<<" "<<x.first<<endl;
    }






    return 0;
}

