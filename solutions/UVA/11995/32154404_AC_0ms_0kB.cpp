// Author : tawfik shalash
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//88888888888888888888888 tawfik shalash 8888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
//8888888888888888888888888888888888888888888888888888888888888//
#include <bits/stdc++.h>
//cpp 11
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl "\n"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;

int main()
{

    // fast
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;

    while (scanf("%d", &n) != EOF)
    {
        stack<int> st;
        queue<int> qu;
        priority_queue<int> pq;

        int Stack = 1, Queue = 1, Prior = 1;
        int a, b;
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &a, &b);
            if (a == 1)
            {
                if (Stack != 0)
                    st.push(b);
                if (Queue != 0)
                    qu.push(b);
                if (Prior != 0)
                    pq.push(b);
            }
            else
            {
                if (Stack != 0)
                    if (st.empty()||st.top() != b)
                        Stack = 0;
                if (Queue != 0)
                    if (qu.empty()||qu.front() != b)
                        Queue = 0;
                if (Prior != 0)
                    if (pq.empty()||pq.top() != b)
                        Prior = 0;

                if (Stack != 0)
                    st.pop();
                if (Queue != 0)
                    qu.pop();
                if (Prior != 0)
                    pq.pop();
            }
        }

        int sum = Stack + Queue + Prior;
        if (sum >= 2)
        {
            printf("not sure\n");
        }
        else if (sum == 0)
        {
            printf("impossible\n");
        }
        else if (Stack == 1)
        {
            printf("stack\n");
        }
        else if (Queue == 1)
        {
            printf("queue\n");
        }
        else if (Prior == 1)
        {
            printf("priority queue\n");
        }
    }

    return 0;
}