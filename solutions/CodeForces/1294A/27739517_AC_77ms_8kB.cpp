
#include <iostream>
#include <string>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    int z;
    cin>>z;
    for(int w=0;w<z;w++)
    {
        int a, b, c, n, ma, l;
        cin >> a >> b >> c >> n;
        ma = max(a, max(b, c));
        l = ma * 3 - (a + b + c);
        if (l > n) {
            cout << "NO"<<endl;
            continue;
        } else
            n = n - l;
        if (n % 3 == 0)
            cout << "YES"<<endl;
        else
            cout << "NO"<<endl;
    }

    return 0;
}
