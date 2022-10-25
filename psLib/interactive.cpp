#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ll l = 1, r = 1e9;
    ll mid = (l + r + 1) / 2;
    while (l <= r)
    {
        mid = (l + r) / 2;
        printf("%lld\n", mid);
        fflush(stdout);

        char response[3];
        scanf("%s", response);

        if (strcmp(response, "<") == 0)
            r = mid - 1;
        else if (strcmp(response, ">") == 0)
            l = mid + 1;
        else if (strcmp(response, "=") == 0)
        {
            break;
        }
        mid = (l + r) / 2;
    }

    printf("! %lld\n", mid);
    fflush(stdout);

    return 0;
}
