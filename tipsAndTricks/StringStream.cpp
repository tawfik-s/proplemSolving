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

int main() {

   // fast
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

/*  input will be like
3
10 20 30 40
7 5 12
125 15 25

*/


    int n,i,j;
    scanf("%d",&n);
    getchar();   // to move down
    while(n--)
    {
        char line[310];
        int data[310];
        int N=0;
        gets(line);      //we will git the line and cut it into peases the line will be stored in char array
        stringstream in(line);//A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream (like cin).
        /* its like string tokenizer in java
         * clear() — to clear the stream
str(        ) — to get and set string object whose content is present in stream.
oper        ator << — add a string to the stringstream object.
oper        ator >> — read something from the stringstream object,
         */
        while(in>>data[N])   // read and store in data[N] untill end
        {
            N++;             //count the number of strings
        }
        int ans=0;
        for(i=0;i<N;i++)
        {
             cout<<data[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
