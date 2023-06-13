#include <bits/stdc++.h>

long long ans = 0;
void merge(long long *arr, int low, int high, int mid)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left++]);
        }
        else
        {
            ans += mid - left + 1;
            temp.push_back(arr[right++]);
        }
    }

    while (left <= mid)
        temp.push_back(arr[left++]);
    while (right <= high)
        temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(long long *arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, high, mid);
}

long long getInversions(long long *arr, int n)
{
    // Write your code here.
    mergeSort(arr, 0, n - 1);
    return ans;
}
