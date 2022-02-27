// Author : tawfik shalash
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//

#include <bits/stdc++.h>
using namespace std;
int n;
set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
vector<bool> prime;
set<vector<int>> final;
void backtrack(vector<int> v, vector<bool> visited)
{
    if (v.size() == n)
    {
        if (prime[v[0] + v[n - 1]])
        {
            final.insert(v);
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (v.empty() || (prime[i + v.back()] && !visited[i]))
            {
                visited[i] = true;
                v.push_back(i);
                backtrack(v, visited);
                v.pop_back();
                visited[i] = false;
            }
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    prime.resize(50, false);
    for (auto i : primes)
    {
        prime[i] = true;
    }
    int count = 0;
    while (cin >> n)
    {
        if(count!=0)
             cout<<endl;
        final.clear();
        count++;
        vector<bool> visited(n + 1, false);
        vector<int> vv;
        visited[1] = true;
         vv.push_back(1);
        backtrack(vv, visited);
        cout << "Case " << count << ":" << endl;
        int counter=0;
        for (auto i : final)
        {
            counter=0;
            for (auto j : i)
            {
                counter++;
                cout << j ;
                if(counter!=n)
                    cout<<" ";
            }
            cout << endl;
        }
    }

    return 0;
}
