#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int n,m; 
	cin >> n >> m;
	
	string st1,st2;
	 cin >> st1;
     cin >> st2;
	
	string st3="...." ; 
  st3[0]=st1.front();
  st3[1]=st1.back();
  st3[2]=st2.front();
  st3[3]=st2.back();
	
	cout << (st3 == "<>v^" || st3 == "><^v" ? "YES" : "NO");
}



