//Approach 1 nlogn

#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n)
{
    // Write your code here.
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;
    int ans = INT_MIN;
    for (auto &i : mp)
    {
        if (i.second > (n / 2))
            ans = max(ans, i.first);
    }
    return ans == INT_MIN ? -1 : ans;
}

//Approach 2 O(n) time and O(1) space
//Moore's Voting Algorithm

#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n)
{
    // Write your code here.
    int el;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            el = arr[i];
            cnt = 1;
        }
        else if (el == arr[i])
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }

    int temp = count(arr, arr + n, el);
    if (temp > (n / 2))
        return el;
    return -1;
}
