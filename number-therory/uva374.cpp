
/*
author: tawfik shalash
─▄█▄─█▀█▀█─▄█▄
▀▀████▄█▄████▀▀
─────▀█▀█▀

*/


#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


//tawfik shalash

/*
بسم الله الرحمن الرحيم

intput

3
18132
17
17
1765
3
2374859
3029382
36123

*/
ll b ,p , m;


ll solve(ll b,ll p)
{

    b=b%m;
    if(p==0)
        return 1;
    else if (p==1)
        return b;

    ll a=solve(b,(p/2))%m;

    if(p%2==1)
        return (((a*a)%m)*b);
    else
        return (a*a);

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

        while(cin>>b>>p>>m)
        {
            cout<<solve(b,p)%m<<endl;
        }
        return 0;

}
