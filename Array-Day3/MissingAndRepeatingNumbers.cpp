#include <bits/stdc++.h>

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    // Write your code here
    int sumArr = 0, sumNum = 0, sumSqArr = 0, sumSqNum = 0;
    for (int i = 0; i < n; i++)
    {
        sumArr += arr[i];
        sumNum += i + 1;
        sumSqArr += arr[i] * arr[i];
        sumSqNum += (i + 1) * (i + 1);
    }
    int a = sumArr - sumNum;
    int b = sumSqArr - sumSqNum;
    int c = b / a;
    return {(c - a) / 2, (a + c) / 2};
}
