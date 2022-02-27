// Author : tawfik shalash

#include <vector>
#include <list>
#include <map>
#include <math.h>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <string.h>
#include <iostream>


using namespace std;

typedef long long ll;
typedef unsigned long long ull;

//seives


ll seivesCountPrimes(int n)
{
    vector<bool>is_prime(n+1,true);
    is_prime[0]=is_prime[1]=0;
    for(ll i=2;i*i<=n;++i){
        if(is_prime[i]){
            for(ll j=i*2;j<=n;j+=i)
                is_prime[j]=0;
        }
    }

    ll cnt=0;
    for(auto i:is_prime)
        if(i)
            cnt++;
    return cnt;
}

vector<ll> factorization(ll n)
{
    vector<ll>primes;

    for(ll i=2;i*i<=n;++i)
        while(n%i==0)
        {
            primes.push_back(i);
            n/=i;
        }
    if(n>1)
        primes.push_back(n);

    return primes;
}

bool factorization2(ll n)
{


    set<ll>myset;

    for(ll i=2;i<=n;++i) {
        while (n % i == 0) {

            myset.insert(i);
            n /= i;

        }
    }

    if(myset.size()==2) {return true; }

    return false ;
}


vector<int> Divisors(int n)
{
    vector<int> v;
    for (int i=1;i<=n;i++)
        if (n%i==0)
            v.push_back(i);

        return v;
}

vector<ll> Divisors2(ll n)
{
    vector<ll> v;
    for (ll i=1; i<=(ll)sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i == i)
                v.push_back(i);
            else
            {
                v.push_back(i);
                v.push_back(n/i);
            }
        }
    }
    return v;
}

int main() {

   ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

ll n,m;

cin>>n>>m;

vector<ll> v= Divisors2(n);
sort(v.begin(),v.end());
if(v.size()<m)
{
    cout<<-1;
}
else
{
    cout<<v[m-1];
}




    return 0;
}