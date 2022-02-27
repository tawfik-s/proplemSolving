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
typedef vector<int> vi;
map<ll,ll>mp;
int countDivisors(int n)
{
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i)
                cnt++;
            else
            cnt = cnt + 2;
        }
    }
    return cnt;
}

vi result;
int A,B,C;
void solve()
{
    for(int a=1;a<=A;a++)
        for(int b=1;b<=B;b++)
            for(int c=1;c<=C;c++)
            {
                result.push_back(a*b*c);
            }

}
int main() {

    fast
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    cin>>A>>B>>C;


    solve();

    ll count=0;
    for(auto i:result)
    {
        if(mp.find(i)==mp.end()) {
            ll k= countDivisors(i);
            count += k;
            mp[i]=k;
        }
        else
        {
            count+=mp[i];
        }
       // cout<<mp[i]<<endl;
    }

    cout<<count;



    return 0;
}