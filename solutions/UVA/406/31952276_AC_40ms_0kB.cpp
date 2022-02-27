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

ll _seive_size;
bitset<10000010> bs;

vi primes;

void seive(ll upper_bound)
{
    primes.push_back(1);
    _seive_size=upper_bound+1;       // add 1 to include upperbound
    bs.set();    // function to set all bits 1 in the bitset;
    bs[0]=bs[1]=0;
    for(ll i=2;i<=_seive_size;i++)
        if(bs[i])
        {
            //then we will cross out multiples of i sttarting from i*i!
            for(ll j=i*i;j<=_seive_size;j+=i)
                bs[j]=0;
            primes.push_back((int)i);
        }
}

int main() {

    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    //modivied sieve
    int n, c, i, j; ll pt ;
    seive(1001);

    vector<int>Primes=primes;

    pt=Primes.size();

    while(cin>>n) {
        cin>>c;
        cout<<n<<" "<<c<<":";
        vector<int>ff;
        for(i = 0; i < pt; i++) {
            if(Primes[i] <= n)
                ff.push_back(Primes[i]) ;
            else
                break;
        }

        if(ff.size()%2!=0) {
            c = c * 2 - 1;
        }
        else {
            c = c * 2;
        }

        if(c > ff.size()) {
            c = ff.size();
        }

        //print element which is with us
        for(i = ff.size()/2-c/2, j = 0; j < c; j++, i++)
            cout<<" "<<ff[i];
        cout<<endl<<endl;
    }


    return 0;
}
