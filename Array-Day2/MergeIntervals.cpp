#include <bits/stdc++.h>
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    // if(n==1) return ans;
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    vector<int> temp = intervals[0];

    for (int i = 1; i < intervals.size(); i++)
    {
        if (temp[1] >= intervals[i][0])
        {
            temp[1] = max(temp[1], intervals[i][1]);
        }
        else
        {
            ans.push_back(temp);
            temp[0] = intervals[i][0];
            temp[1] = intervals[i][1];
        }
    }
    ans.push_back(temp);
    return ans;
}
