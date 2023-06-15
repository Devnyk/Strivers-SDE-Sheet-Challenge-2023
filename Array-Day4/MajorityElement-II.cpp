#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int el1 = -1, el2 = -2, cnt1 = 0, cnt2 = 0, n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 and el2 != arr[i])
        {
            cnt1 = 1;
            el1 = arr[i];
        }
        else if (cnt2 == 0 and el1 != arr[i])
        {
            cnt2 = 1;
            el2 = arr[i];
        }
        else if (el1 == arr[i])
        {
            cnt1++;
        }
        else if (el2 == arr[i])
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    vector<int> ans;
    int c1 = 0, c2 = 0;
    for (auto &i : arr)
    {
        c1 += (i == el1);
        c2 += (i == el2);
    }
    if (c1 > (n / 3))
        ans.push_back(el1);
    if (c2 > (n / 3))
        ans.push_back(el2);
    sort(ans.begin(), ans.end());
    return ans;
}
