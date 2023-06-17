#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    // Write your code here.
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    map<int, int> mp;
    for (auto &i : arr)
    {
        int diff = s - i;
        if (mp.find(diff) != mp.end())
        {
            for (int k = 0; k < mp[diff]; k++)
            {
                ans.push_back({min(i, diff), max(i, diff)});
            }
        }
        mp[i]++;
    }
    sort(ans.begin(), ans.end());
    return ans;
}
