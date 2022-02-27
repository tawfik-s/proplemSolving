
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

bool check(const string &s)
{
    string rev(s);
    reverse(rev.begin(), rev.end());
    return s == rev;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif


    string s;
    while(cin>>s)
    {
        int c=0;
        map<string,int>mp;
         for(int i=0;i<s.size();i++)
         {
             for(int j=i;j<s.size();j++)
             {
                 string su = s.substr(i, j - i + 1);
                 if(check(su) && mp.find(su) == mp.end())
                 {
                     c++;
                     mp[su]=1;
                 }

             }

         }




        cout << "The string '"<< s << "' contains "<< c<< " palindromes."<< endl;
    }


    return 0;
}

