// Author : tawfik shalash
#include <vector>
#include <list>
#include <map>
#include <math.h>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <string.h>
#include <iostream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// check if the number is power of two we have two fuction
// one is o(logN)  and another one o(1);
bool isPowerOfTwo(int x)
{
    if (x == 0)
        return false;
    else
    {
        while (x % 2 == 0)
            x /= 2;
        return (x == 1);
    }
}
bool isPowerOfTwo(int x)
{
    // x will check if x == 0 and !(x & (x - 1)) will check if x is a power of 2 or not
    return (x && !(x & (x - 1)));
    // x-1 will return the 01111 if number is 10000
    // x and x-1  will return 0 if true;
    //! 0 will return 1  && x= x  mean return true;
}

// count the number of ones in the binary representation of the given number
//   __
int count_one(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1); // will make each one =0 in each step until reach n=0
        count++;
    }
    return count;
}

/*
the basic approach to evaluate the binary form of a number
is to traverse on it and count the number of ones but this approach takes log2n of time in every case


*/

///////////////////////////////////////
// check the ith bit is set in the binary form of the given number
bool check(int n, int i) // n is the number you will check in it and the i is the number of bits.
{

    if (n & (1 << i)) //(1<<i)  will return the number 2^i
    {
        return true;
    }
    else
        return false; // number is not set
}

// generating all the possible subsets of a set
void possible_subsets(vector<char> v)
{
    int N = v.size();
    for (int i = 0; i < (1 << N); ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (i & (1 << j))
                cout << v[j] << ' ';
        }
        cout << endl;
    }
}

// some tricks
/*

x^(x&(x-1))  : return the rightmost 1 in binary representation of x

(-x) is the two’s complement of x. (-x) will be equal to one’s complement of x plus 1.

x = 10 = (1010)2
(-x) = -10 = (0110)2
x & (-x) = (1010)2 & (0110)2 = (0010)2


*/

int main()
{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    return 0;
}
