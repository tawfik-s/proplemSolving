// Author : tawfik shalash
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//

#include<bits/stdc++.h>

using namespace std;


int main()
{

#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif

vector<int> v;   //empty vector of int
vector<int> v2(4,100);  //set 4 ints with value 100
vector<int>v3(v2.begin(),v2.end()); //iterate around v2 to copy data to v3
vector<int>v4(v3); //copy all data in v3 into v4

int myints[]={1,2,3,4,5};

vector<int>v5(myints,myints+5);





    return 0;
}





