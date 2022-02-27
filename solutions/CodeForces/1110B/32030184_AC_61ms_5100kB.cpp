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

unsigned int factorial(unsigned int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

int n,m,k;
cin>>n>>m>>k;
vector<int>v;
vector<int>pro;
v.resize(n);

for(int i=0;i<n;i++)
{
    cin>>v[i];
}

for(int i=1;i<n;i++)
{
    pro.push_back((v[i]-v[i-1]));
}

sort(pro.begin(),pro.end());
int sum=0;
for(int i=0;i<pro.size()-k+1;i++)
{
    sum+=pro[i];
}
sum+=k;
cout<<sum;


    return 0;
}