// Author : tawfik shalash
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
#include<bits/stdc++.h>

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
bool factork(int N)
{
    si factors;

    int PF=2;
    while(PF*PF<=N)
    {
        while(N%PF==0)
        {
            N/=PF;
            factors.insert(PF);
        }
        PF++;
    }
    if(N!=1)factors.insert(N);
    if(factors.size()==2)
    {
        return true;
    }
    return false;
}

ll d=1073741824;

ll Divisors(ll n)
{
   ll count=0;
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                count++;

            else // Otherwise print both
                count+=2;
        }
    }
    return count;
}
bool dd(ll n)
{
    if(n==1||n==2||n==3)
    {
        return false;
    }
    int sq=sqrt(n);
    if(sq*sq==n)
    {
        return true;
    }

    ll count=0;
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                count++;

            else // Otherwise print both
                count+=2;
        }
        if(count>=3)
            return true;
    }


    return false;
}
ll _seive_size;
bitset<10000010> bs;

vi primes;

void seive(ll upper_bound)
{
    _seive_size=upper_bound+1;       // add 1 to include upperbound
    bs.set();    // function to set all bits 1 in the bitset;
    bs[0]=bs[1]=0;
    for(ll i=2;i<=_seive_size;i++) if(bs[i])
        {
            //then we will cross out multiples of i sttarting from i*i!
            for(ll j=i*i;j<=_seive_size;j+=i) bs[j]=0;
            primes.push_back((int)i);
        }
}

bool isPrime(ll N){   // a good enough deterministic prime tester
    if(N<=_seive_size) return bs[N];

    for(ll i=0;i<(ll)primes.size();i++)
        if(N%primes[i]==0)return false;
    return true;
}
bool isPrime2(ll n)
{
    // Corner case
    if (n <= 1)
        return false;
    if(n==2)
        return true;
    if(n%2==0)
        return false;

    // Check from 2 to square root of n
    for (int i = 3; i <= sqrt(n); i+=2)
        if (n % i == 0)
            return false;

    return true;
}
int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
int n;
cin>>n;
while(n--) {
    ll t;
    cin >> t;
    ll j=sqrt(t);
    if (t!=1&&(j*j==t&& isPrime2(j))) {
        cout << "YES" << endl;
    } else
    {
        cout<<"NO"<<endl;
    }
}
    return 0;
}
