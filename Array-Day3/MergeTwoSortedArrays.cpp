#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    // Write your code here.
    int i = 0, j = 0, k = 0;
    vector<int> ans(m + n);
    while (i < m and j < n)
    {
        if (arr1[i] <= arr2[j])
        {
            ans[k++] = arr1[i++];
        }
        else
        {
            ans[k++] = arr2[j++];
        }
    }
    while (i < m)
        ans[k++] = arr1[i++];
    while (j < n)
        ans[k++] = arr2[j++];
    return ans;
}
