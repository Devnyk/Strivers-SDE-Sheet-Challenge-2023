#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m)
{
    // Write your code here.

    long int ans = 1;
    while (n > 0)
    {
        if (n % 2 != 0)
        {
            ans = (1LL * (ans) * (x % m)) % m;
        }
        x = (1LL * (x % m) * (x % m)) % m;
        n /= 2;
    }

    return (ans % m);
}
