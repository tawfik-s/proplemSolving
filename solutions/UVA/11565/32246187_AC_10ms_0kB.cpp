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

  //  fast
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    int n,a,b,c;

    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d %d",&a,&b,&c);

        bool flag=false;
         int i,j,k;
        for( i=-100;i<=100&&!flag;i++)
        {
            if (i * i <= c)
            for( j=-100;j<=100&&!flag;j++)
            {
                if (j != i && i * i + j * j <= c)
                for( k=-100;k<=100&&!flag;k++) {
                    if ((k!=i)&&(k!=j)&&(i + j + k == a) && (i * j * k == b) && ((i * i) + (j * j) + (k * k) == c)) {
                        printf("%d %d %d\n",i,j,k);
                        flag = true;

                    }

                    if (flag)
                        break;
                }
            }
            if(flag)
                break;
        }
        if(!flag)
            printf("No solution.\n");
    }




    return 0;
}