#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n)
{
    sort(arr.begin(), arr.end());
    // Write your code here.
    for (int i = 0; i < n; i++)
    {
        if (i != 0 and arr[i] == arr[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j != i + 1 and arr[j] == arr[j - 1])
                continue;

            int k = j + 1, l = n - 1;
            while (k < l)
            {
                long long sum = arr[i] + arr[j] + arr[k] + arr[l];
                if (sum == target)
                {
                    return "Yes";
                }
                else if (sum > target)
                    l--;
                else
                    k++;
            }
        }
    }

    return "No";
}
