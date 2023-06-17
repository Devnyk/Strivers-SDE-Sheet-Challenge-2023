#include <bits/stdc++.h>

void merge(vector<int> &arr, int low, int high, int mid)
{
    vector<int> temp;
    int left = low, right = mid + 1;
    while (left <= mid and right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left++]);
        }
        else
        {
            temp.push_back(arr[right++]);
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left++]);
    }

    while (right <= high)
    {
        temp.push_back(arr[right++]);
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

int countPairs(vector<int> &arr, int low, int high, int mid)
{
    int ans = 0;
    int right = mid + 1;
    for (int left = low; left <= mid; left++)
    {
        while (right <= high and arr[left] > (2 * arr[right]))
            right++;
        ans += right - mid - 1;
    }

    return ans;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    int ans = 0;
    if (low >= high)
        return ans;
    int mid = low + (high - low) / 2;
    ans += mergeSort(arr, low, mid);
    ans += mergeSort(arr, mid + 1, high);
    ans += countPairs(arr, low, high, mid);
    merge(arr, low, high, mid);

    return ans;
}

int reversePairs(vector<int> &arr, int n)
{
    // Write your code here.
    return mergeSort(arr, 0, n - 1);
}
