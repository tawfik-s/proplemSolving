#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
#define fast     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

//////////////////////seive eratosthenes.
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

    for(int i=0;i<(int)primes.size();i++)
        if(N%primes[i]==0)return false;
    return true;
}




int main(){




seive(1000);

for(auto i:primes)
{
    cout<<i <<endl;
}


    return 0;
}