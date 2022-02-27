
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
int Max = 1e9;



int p,q,r,s,t,u;

double solve(double mid){
    double val= p*exp(-mid)+q*sin(mid)+r*cos(mid)+s*tan(mid)+t*mid*mid+u;
    return val;
}



int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    while(cin>>p ){
        cin>>q>>r>>s>>t>>u;

        if(solve(1)*solve(0) > 0) {
            cout << "No solution\n";
            continue;
        }
        double l = 0, r = 1;
            double mid;
            double val;
            while((r - l) > 1e-10){
                mid = (l + r) / 2;
                val = solve(mid);

                if(val > 0) {
                    l = mid;
                }
                else {
                    r = mid;
                }
            }
              cout<<setprecision(4)<<fixed<<mid<<endl;

    }


    return 0;

}
