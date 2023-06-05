#include <bits/stdc++.h>

long long int nCr(int n, int r)
{
    long long int res = 1;
    if (r > n - r)
        r = n - r;
    for (int i = 0; i < r; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

vector<vector<long long int>> printPascal(int n)
{
    // Write your code here.
    vector<vector<long long int>> ans;
    for (int i = 0; i < n; i++)
    {
        vector<long long int> temp;
        for (int j = 0; j <= i; j++)
        {
            temp.push_back(nCr(i, j));
        }
        ans.push_back(temp);
    }

    return ans;
}
