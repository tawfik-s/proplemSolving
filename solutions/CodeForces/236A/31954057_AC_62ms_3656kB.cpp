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
    cin>>s;
    int arr[26]={0};
    for(int i=0;i<s.size();i++)
    {
        arr[s[i]-'a']++;
    }
    int count=0;
    for(int i=0;i<26;i++)
    {
        if(arr[i]!=0)
        {
            count++;
        }
    }

    if(count%2==0)

    cout<<"CHAT WITH HER!"<<endl;

    else
        cout<<"IGNORE HIM!"<<endl;


    return 0;
}