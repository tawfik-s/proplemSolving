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

    int tc, a, b, c;

    scanf("%d", &tc);
    while (tc--) {

        scanf("%d %d %d", &a, &b, &c);

        bool flag = false;
        int x, y, z;

        for (x = -100; x <= 100 && !flag; x++)
        {
            if (x * x <= c) {
                for (y = -100; y <= 100 && !flag; y++) 
                {
                    if (y != x && x * x + y * y <= c) {
                        for (z = -100; z <= 100 && !flag; z++) 
                        {
                            if (z != x && z != y && x + y + z == a && x * y * z == b && x * x + y * y + z * z == c) {
                                printf("%d %d %d\n", x, y, z);
                                flag = true;
                            }
                        }
                    }
                }
            }
        }
        if (!flag)
            printf("No solution.\n");
    }




    return 0;
}